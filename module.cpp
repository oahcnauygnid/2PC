/*
Created by dingyc.
2022.
*/
#include "module.h"


#define MAX_LEN 4096

#define ROLE_CLIENT 0x00
#define ROLE_SERVER 0x01

AHE *ahe;

/*
* 生成三元组（HE-based）
*/
int N = 1048576;//2**20=1048576

void dot_product_triplet_generation(vector<double> &vector_w,vector<double> &vector_r,double &u,double &v){
    
    size_t n = ahe->slot_count;
    double _v[n];
    for (size_t i = 0; i < n; i++){
        _v[i] = rand()%N;
    }
    vector<double> vector_v(_v,_v+n);
    Plaintext plain_v;
    ahe->AHE_CODE(vector_v,plain_v);

    cout<< "server: enc(w) = [w]"<<endl;
    Ciphertext cipher_w;
    ahe->AHE_ENC(ahe->encryptor,vector_w,cipher_w);
    
    cout<< "comm: server === cipher_w ===> client"<<endl;

    cout<< "client: r·[w]-v = [u]"<<endl;
    Ciphertext cipher_u0,cipher_u;
    ahe->AHE_MUL(cipher_w,vector_r,cipher_u0);
    ahe->evaluator->rescale_to_next_inplace(cipher_u0);
    cipher_u0.scale() = ahe->scale;
    parms_id_type last_parms_id = cipher_u0.parms_id();
    ahe->evaluator->mod_switch_to_inplace(plain_v, last_parms_id);
    ahe->evaluator->sub_plain(cipher_u0,plain_v,cipher_u);

    cout<< "comm: client === cipher_u ===> server"<<endl;

    cout<< "server: dec([u])=u, and u=sum(u)"<<endl;
    vector<double> vector_u;
    ahe->AHE_DEC(ahe->decryptor,cipher_u,vector_u);
    u = accumulate(vector_u.begin(),vector_u.end(),0.0);

    cout<< "client: v=sum(v)"<<endl;
    v = accumulate(vector_v.begin(),vector_v.end(),0.0);



}

void test()
{
    // comm
    Role client(ROLE_CLIENT, "workdir/client", "127.0.0.1", 22222);
    Role server(ROLE_SERVER, "workdir/server", "127.0.0.1", 11111);
    client.comm(server, "1.txt", "1.bak.txt");
    server.comm(client, "2.txt", "2.bak.txt");
    cout<<"___comm ok______________________"<<endl;
    // AHE
    ahe = new AHE();
    double x[] = {1.5, 2, 3};
    double x1[] = {3, 2, 1.5};
    vector<double> input1(x, x + 3);
    vector<double> input2(x1, x1 + 3);
    vector<double> output1, output2, output_add, output_mul, output_sub_plain;
    Ciphertext cipher1, cipher2, cipher_add, cipher_mul, cipher_sub_plain;

    ahe->AHE_ENC(ahe->encryptor, input1, cipher1);
    ahe->AHE_DEC(ahe->decryptor, cipher1, output1);
    ahe->AHE_ENC(ahe->encryptor, input2, cipher2);
    ahe->AHE_DEC(ahe->decryptor, cipher2, output2);
    ahe->AHE_ADD(cipher1,cipher2,cipher_add);
    ahe->AHE_DEC(ahe->decryptor, cipher_add, output_add);
    ahe->AHE_MUL(cipher1,input1,cipher_mul);
    ahe->AHE_DEC(ahe->decryptor, cipher_mul, output_mul);
    ahe->evaluator->rescale_to_next_inplace(cipher_mul);
    cipher_mul.scale() = ahe->scale;
    Plaintext plaintext;
    ahe->AHE_CODE(input1,plaintext);
    
    parms_id_type last_parms_id = cipher_mul.parms_id();
    ahe->evaluator->mod_switch_to_inplace(plaintext, last_parms_id);
    ahe->evaluator->multiply_plain(cipher_mul,plaintext,cipher_sub_plain);
    //ahe->AHE_SUB_PLAIN(cipher_mul,input1,cipher_sub_plain);
    //ahe->AHE_DEC(ahe->decryptor, cipher_sub_plain, output_sub_plain);

    cout << "input1: " << endl;
    print_vector(input1);
    cout << "output1: " << endl;
    print_vector(output1);
    cout << "input2: " << endl;
    print_vector(input2);
    cout << "output2: " << endl;
    print_vector(output2);

    cout << "output_add = [input1] + [input2]: " << endl;
    print_vector(output_add);
    cout << "output_mul = [input1] * input1: " << endl;
    print_vector(output_mul);
    cout << "output_sub_plain = [cipher_mul] - input1: " << endl;
    //print_vector(output_sub_plain);

    cout<<"____AHE ok_______________________"<<endl ;

    int n = ahe->slot_count;
    double w[n]={1,2,3},r[n]={1,2,3};
    vector<double> vector_w(w,w+3);
    vector<double> vector_r(r,r+3);
    double u=0.0,v=0.0;
    dot_product_triplet_generation(vector_w,vector_r,u,v);
    cout << "w·r = "<< inner_product(vector_w.begin(),vector_w.end(),vector_r.begin(),0.0) <<endl;
    cout << "u+v = "<<u+v<<endl;
    cout<<"____dot_product_triplet_generation ok_______________________"<<endl ;


    delete ahe;
}

int main()
{

    test();
    return 0;
}