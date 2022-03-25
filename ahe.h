/*
* 加同态加密，CKKS方案，使用其中的加法和标量乘运算
*/

#include "seal/seal.h"
using namespace seal;

class AHE{

public:

    Encryptor *encryptor;
    CKKSEncoder *encoder;
    Decryptor *decryptor;
    Evaluator *evaluator;
    double scale;
    size_t slot_count;

    /*
    * encode，将double编码为plaintext，即实数域到明文域
    */
    void AHE_CODE(vector<double> plain, Plaintext& plaintext){
        plain.reserve(slot_count);
        encoder->encode(plain, scale, plaintext);
    }
    /*
    * decode，plaintext解码为double，即明文域到实数域
    */
    void AHE_DECODE(vector<double> plain, Plaintext& plaintext){
        encoder->decode(plaintext, plain);
    }

    /*
    * AHE加密，公钥包含在encryptor中
    */
    void AHE_ENC(Encryptor *encryptor, vector<double> plain, Ciphertext &res){

        Plaintext x_plain;
        AHE_CODE(plain,x_plain);
        encryptor->encrypt(x_plain, res);
    }
    /*
    * AHE解密，私钥包含在decryptor中
    */
    void AHE_DEC(Decryptor *decryptor, Ciphertext cipher, vector<double> &plain){
        Plaintext plain_result;
        decryptor->decrypt(cipher, plain_result);
        encoder->decode(plain_result, plain);

    }

    /*
    * AHE加法，密文+密文=密文
    */
    void AHE_ADD(Ciphertext cipher1, Ciphertext cipher2, Ciphertext &cipher_add){
        evaluator->add(cipher1,cipher2,cipher_add);
    }
    /*
    * AHE减法，密文-明文=密文
    */
    void AHE_SUB_PLAIN(Ciphertext cipher, vector<double> plain, Ciphertext &cipher_sub_plain){
        Plaintext plaintext;
        AHE_CODE(plain,plaintext);
        evaluator->sub_plain(cipher,plaintext,cipher_sub_plain);
    }
    /*
    * AHE分量乘法，密文*明文=密文
    */
    void AHE_MUL(Ciphertext cipher, vector<double> plain, Ciphertext &cipher_mul){
        Plaintext plaintext;
        AHE_CODE(plain,plaintext);
        evaluator->multiply_plain(cipher,plaintext,cipher_mul);
    }


    /*
    * AHE的setup，初始化CKKS参数
    */
    AHE(){

        EncryptionParameters parms(scheme_type::ckks);
        size_t poly_modulus_degree = 8192;
        parms.set_poly_modulus_degree(poly_modulus_degree);
        parms.set_coeff_modulus(CoeffModulus::Create(poly_modulus_degree, {60, 40, 40, 60}));
        scale = pow(2.0, 40);
        SEALContext context(parms);
        // print_parameters(context);

        KeyGenerator keygen(context);
        SecretKey secret_key = keygen.secret_key();
        PublicKey pubkey;
        keygen.create_public_key(pubkey);
        RelinKeys relin_keys;
        keygen.create_relin_keys(relin_keys);
        GaloisKeys gal_keys;
        keygen.create_galois_keys(gal_keys);

        encoder = new CKKSEncoder(context);
        slot_count = encoder->slot_count();

        encryptor = new Encryptor(context, pubkey);
        decryptor = new Decryptor(context, secret_key);
        evaluator = new Evaluator(context);

    }
    ~AHE(){
        delete encryptor;
        delete encoder;
        delete decryptor;
        delete evaluator;
    }
};


