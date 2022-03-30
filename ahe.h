/*
* 加同态加密，CKKS方案，使用其中的加法和标量乘运算
*/
#pragma once
#include "seal/seal.h"

class AHE{

public:

    seal::Encryptor *encryptor;
    seal::CKKSEncoder *encoder;
    seal::Decryptor *decryptor;
    seal::Evaluator *evaluator;
    double scale;
    size_t slot_count;

    /*
    * encode，将double编码为plaintext，即实数域到明文域
    */
    void AHE_CODE(std::vector<double> plain, seal::Plaintext& plaintext){
        plain.reserve(slot_count);
        encoder->encode(plain, scale, plaintext);
    }
    /*
    * decode，plaintext解码为double，即明文域到实数域
    */
    void AHE_DECODE(std::vector<double> plain, seal::Plaintext& plaintext){
        encoder->decode(plaintext, plain);
    }

    /*
    * AHE加密，公钥包含在encryptor中
    */
    void AHE_ENC(seal::Encryptor *encryptor, std::vector<double> plain, seal::Ciphertext &res){

        seal::Plaintext x_plain;
        AHE_CODE(plain,x_plain);
        encryptor->encrypt(x_plain, res);
    }
    /*
    * AHE解密，私钥包含在decryptor中
    */
    void AHE_DEC(seal::Decryptor *decryptor, seal::Ciphertext cipher, std::vector<double> &plain){
        seal::Plaintext plain_result;
        decryptor->decrypt(cipher, plain_result);
        encoder->decode(plain_result, plain);

    }

    /*
    * AHE加法，密文+密文=密文
    * 其中的mod_switch在于CKKS方案还要求模数一致，在乘法后会改变scale，
    * 然后缩小scale时并不是一步到位，而是找了一个差不多大小的模数，所以还需要再把模数统一
    */
    void AHE_ADD(seal::Ciphertext cipher1, seal::Ciphertext cipher2, seal::Ciphertext &cipher_add, bool mod_switch=0){
        if(mod_switch){
            seal::parms_id_type last_parms_id = cipher2.parms_id();
            evaluator->mod_switch_to_inplace(cipher1, last_parms_id);
        }
        evaluator->add(cipher1,cipher2,cipher_add);
    }
    /*
    * AHE减法，密文-明文=密文
    */
    void AHE_SUB_PLAIN(seal::Ciphertext cipher, std::vector<double> plain,seal:: Ciphertext &cipher_sub_plain, bool mod_switch=0){
        seal::Plaintext plaintext;
        AHE_CODE(plain,plaintext);
        if(mod_switch){
            seal::parms_id_type last_parms_id = cipher.parms_id();
            evaluator->mod_switch_to_inplace(plaintext, last_parms_id);
        }
        evaluator->sub_plain(cipher,plaintext,cipher_sub_plain);
    }
    /*
    * AHE分量乘法，密文*明文=密文
    */
    void AHE_MUL(seal::Ciphertext cipher, std::vector<double> plain, seal::Ciphertext &cipher_mul, bool mod_switch=0){
        seal::Plaintext plaintext;
        AHE_CODE(plain,plaintext);
        if(mod_switch){
            seal::parms_id_type last_parms_id = cipher.parms_id();
            evaluator->mod_switch_to_inplace(plaintext, last_parms_id);
        }
        evaluator->multiply_plain(cipher,plaintext,cipher_mul);
    }


    /*
    * AHE的setup，初始化CKKS参数
    */
    AHE(){

        seal::EncryptionParameters parms(seal::scheme_type::ckks);
        size_t poly_modulus_degree = 8192;
        parms.set_poly_modulus_degree(poly_modulus_degree);
        parms.set_coeff_modulus(seal::CoeffModulus::Create(poly_modulus_degree, {60, 40, 40, 60}));
        scale = pow(2.0, 40);
        seal::SEALContext context(parms);
        // print_parameters(context);

        seal::KeyGenerator keygen(context);
        seal::SecretKey secret_key = keygen.secret_key();
        seal::PublicKey pubkey;
        keygen.create_public_key(pubkey);
        seal::RelinKeys relin_keys;
        keygen.create_relin_keys(relin_keys);
        seal::GaloisKeys gal_keys;
        keygen.create_galois_keys(gal_keys);

        encoder = new seal::CKKSEncoder(context);
        slot_count = encoder->slot_count();

        encryptor = new seal::Encryptor(context, pubkey);
        decryptor = new seal::Decryptor(context, secret_key);
        evaluator = new seal::Evaluator(context);

    }
    ~AHE(){
        delete encryptor;
        delete encoder;
        delete decryptor;
        delete evaluator;
    }
};


