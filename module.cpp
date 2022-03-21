/*
Created by dingyc.
2022.
*/

#include<string>
#include<iostream>
#include "module.h"

#define MAX_LEN 4096


#define ROLE_CLIENT 0x00
#define ROLE_SERVER 0x01


#define INTEGER_LENGTH 64 //整数长度64bit
double scale;
/*
* 生成三元组（HE-based）
*/


void AHE_SETUP(){
    EncryptionParameters parms(scheme_type::ckks);
    size_t poly_modulus_degree = 8192;
    parms.set_poly_modulus_degree(poly_modulus_degree);
    parms.set_coeff_modulus(CoeffModulus::Create(poly_modulus_degree, { 60, 40, 40, 60 }));
    scale = pow(2.0, 40);

    SEALContext context(parms);
    //print_parameters(context);
    cout << endl;

    KeyGenerator keygen(context);
    auto secret_key = keygen.secret_key();
    PublicKey pubkey;
    keygen.create_public_key(pubkey);
    RelinKeys relin_keys;
    keygen.create_relin_keys(relin_keys);
    GaloisKeys gal_keys;
    keygen.create_galois_keys(gal_keys);

    CKKSEncoder encoder(context);
    size_t slot_count = encoder.slot_count();
    
    double x[] = {1.5,2,3};
    double x1[] = {3,2,1.5};
    vector<double> input1(x,x+3);
    vector<double> input2(x1,x1+3);
    vector<double> output1,output2,output_add,output_mul;
    Ciphertext cipher1,cipher2,cipher_add,cipher_mul;

    //AHE_ENC(context,pubkey,input,res);
    Encryptor encryptor(context, pubkey);
    Plaintext x_plain1,x_plain2;
    input1.reserve(slot_count);
    encoder.encode(input1, scale, x_plain1);
    input2.reserve(slot_count);
    encoder.encode(input2, scale, x_plain2);

    encryptor.encrypt(x_plain1, cipher1);
    encryptor.encrypt(x_plain2, cipher2);

    Evaluator evaluator(context);
    //加法
    evaluator.add(cipher1,cipher2,cipher_add);
    //乘法
    evaluator.multiply_plain(cipher1,x_plain1,cipher_mul);


    //AHE_DEC(context,secret_key,res,output);
    Decryptor decryptor(context, secret_key);   
    Plaintext plain_result1,plain_result2,plain_result,plain_mul;
    decryptor.decrypt(cipher1, plain_result1);
    decryptor.decrypt(cipher2, plain_result2);
    decryptor.decrypt(cipher_add, plain_result);
    decryptor.decrypt(cipher_mul, plain_mul);

    encoder.decode(plain_result1, output1);
    encoder.decode(plain_result2, output2);
    encoder.decode(plain_result, output_add);
    encoder.decode(plain_mul, output_mul);


    cout<<"input1: "<<endl;
    print_vector(input1);
    cout<<"output1: "<<endl;
    print_vector(output1);
    cout<<"input2: "<<endl;
    print_vector(input2);
    cout<<"output2: "<<endl;
    print_vector(output2);

    
    cout<<"output_add = [input1] + [input2]: "<<endl;
    print_vector(output_add);
    cout<<"output_mul = [input1] * input1: "<<endl;
    print_vector(output_mul);

    
    
}
void AHE_ENC(SEALContext context,PublicKey pubkey, vector<double> plain, Ciphertext res){
    Encryptor encryptor(context, pubkey);
    Plaintext x_plain;
    CKKSEncoder encoder(context);
    size_t slot_count = encoder.slot_count();
    plain.reserve(slot_count);
    encoder.encode(plain, scale, x_plain);
    encryptor.encrypt(x_plain, res);
}

void AHE_DEC(SEALContext context, auto secret_key, Ciphertext cipher, vector<double> plain){
    Decryptor decryptor(context, secret_key);
    Plaintext plain_result;
    decryptor.decrypt(cipher, plain_result);
    CKKSEncoder encoder(context);
    encoder.decode(plain_result, plain);
}

void AHE_ADD(Ciphertext c1, Ciphertext c2, Ciphertext res){


}
void AHE_MUL(Ciphertext c, double c1[], Ciphertext* res){

    
}

void dot_product_triplet_generation(Role role){
    





}

void test(){
    //comm
    Role client("client","workdir/client","127.0.0.1",22222);
    Role server("server","workdir/server","127.0.0.1",11111);
    client.comm(server,"1.txt","1.bak.txt");
    server.comm(client,"2.txt","2.bak.txt");
    //
}

int main(){
    
    AHE_SETUP();
    return 0;
}