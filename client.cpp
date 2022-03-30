/*
Created by dingyc.
2022.
*/
#include "module.h"

#define CLIENT "client"

int N = 1048576;//2**20=1048576
/*
* 生成三元组（HE-based）
*/


void client_dot_product_triplet_generation(vector<double> &vector_r,double &v){
    
    size_t n = ahe->slot_count;
    
    std::cout<< "client: vector_v <= Z_N^n"<<std::endl;
    double _v[n];
    for (size_t i = 0; i < n; i++){
        _v[i] = rand()%N;
    }
    vector<double> vector_v(_v,_v+n);
    seal::Plaintext plain_v;
    ahe->AHE_CODE(vector_v,plain_v);

    std::cout<< "waiting: server: enc(w) = [w]"<<std::endl;
    receive(CLIENT,"cipher_w");
    std::cout<< "client: r·[w]-v = [u]"<<std::endl;
    seal::Ciphertext cipher_u0;
    ahe->AHE_MUL(cipher_w,vector_r,cipher_u0);
    ahe->evaluator->rescale_to_next_inplace(cipher_u0);
    cipher_u0.scale() = ahe->scale;
    seal::parms_id_type last_parms_id = cipher_u0.parms_id();
    ahe->evaluator->mod_switch_to_inplace(plain_v, last_parms_id);
    ahe->evaluator->sub_plain(cipher_u0,plain_v,cipher_u);

    send(CLIENT,"cipher_u");

    std::cout<< "waiting server: dec([u])=u, and u=sum(u)"<<std::endl;

    std::cout<< "client: v=sum(v)"<<std::endl;
    v = accumulate(vector_v.begin(),vector_v.end(),0.0);

    std::cout<< "client ok"<<std::endl;
}



void client_conv(){


}

void test()
{
    // comm
    {
    Role client(ROLE_CLIENT, "workdir/client", "127.0.0.1", 22222);
    Role server(ROLE_SERVER, "workdir/server", "127.0.0.1", 11111);
    client.comm(server, "1.txt", "1.bak.txt");
    server.comm(client, "2.txt", "2.bak.txt");
    std::cout<<"___ comm ok______________________"<<std::endl;
    // dot_product_triplet
    int n = ahe->slot_count;
    double w[n]={1,2,3},r[n]={1,2,3};
    vector<double> vector_w(w,w+3);
    vector<double> vector_r(r,r+3);
    double u=0.0,v=0.0;
    dot_product_triplet_generation(vector_w,vector_r,u,v);
    std::cout << "w·r = "<< inner_product(vector_w.begin(),vector_w.end(),vector_r.begin(),0.0) <<std::endl;
    std::cout << "u+v = "<<u+v<<std::endl;
    std::cout<<"____ dot_product_triplet_generation ok_______________________"<<std::endl ;

    string model_path = "/home/dingyc/PPML/mywork/2PC/pytorch_test/models/cnn_mnist/mnist_net.pt";
    get_double_params(model_path);
    std::cout<<"con1_0_weight: "<<con1_0_weight[0][0][0][0]<<"... "<<con1_0_weight[15][0][4][4]<<std::endl;
    std::cout<<"con1_0_bias: "<<con1_0_bias[0]<<"... "<<con1_0_bias[15]<<std::endl;
    std::cout<<"con2_0_bias: "<<con2_0_weight[0][0][0][0]<<"... "<<con2_0_weight[32][15][4][4]<<std::endl;
    std::cout<<"con2_0_bias: "<<con2_0_bias[0]<<"... "<<con2_0_bias[31]<<std::endl;
    std::cout<<"fc1_weight: "<<fc1_weight[0][0]<<"... "<<fc1_weight[9][1567]<<std::endl;
    std::cout<<"fc1_bias: "<<fc1_bias[0]<<"... "<<fc1_bias[9]<<std::endl;
    std::cout<<"____ get_double_params ok_______________________"<<std::endl;

    std::cout<<"input[28][28]: "<<input[0][0]<<"... "<<input[27][27]<<std::endl;
    conv1_input_to_mult(input);
    std::cout<<"con1_input_extend[25][496]: "<<con1_input_extend[0][0]<<"... "<<con1_0_weight_extend[24][495]<<std::endl;
    std::cout<<"con1_0_weight: "<<con1_0_weight[0][0][0][0]<<"... "<<con1_0_weight[15][0][4][4]<<std::endl;
    conv1_weight_to_mult();
    std::cout<<"con1_0_weight_extend: "<<con1_0_weight_extend[0][0]<<"... "<<con1_0_weight_extend[15][24]<<std::endl;
    std::cout<<"____ conv1_to_mult ok_______________________"<<std::endl;
    }

    get_rand_params();
    std::cout<<"____ get_rand_params ok______________________"<<std::endl;

    size_t conv1_extend_dims[]={25,496};
    for (size_t i = 0; i < conv1_extend_dims[0]; i++)
        for (size_t j = 0; j < conv1_extend_dims[1]; j++)
            con1_xs_extend[i][j] = con1_input_extend[i][j] - con1_xc_extend[i][j];
    
        
    

    delete ahe;
}

int main()
{

    test();
    return 0;
}