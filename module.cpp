/*
Created by dingyc.
2022.
*/
#include "module.h"

#define MAX_LEN 4096

#define ROLE_CLIENT 0x00
#define ROLE_SERVER 0x01



int N = 1048576;//2**20=1048576
/*
* 生成三元组（HE-based）
*/

typedef struct{
    std::vector<double> *vector;
    double num;
} th_t_dot3gen;

typedef struct{
    float **weight;
    float **xs;
    float **bias;
} th_t_conv_server;

typedef struct{
    float **xc;
} th_t_conv_client;

double server_dot_product_triplet_generation(std::vector<double> *vector_w){

    size_t n = ahe->slot_count;

    //std::cout<< "server: enc(w) = [w]"<<std::endl;
    cipher_w = new  seal::Ciphertext();
    ahe->AHE_ENC(ahe->encryptor,*vector_w,*cipher_w);
    
    //std::cout<< "server === cipher_w ===> client"<<std::endl;
    //send(SERVER,"[w]");
    sem_post(&sem2);

    sem_wait(&sem1);
    //std::cout<< "comm: client === cipher_u ===> server"<<std::endl;
    //receive(SERVER,"[u]");

    //std::cout<< "server: dec([u])=u, and u=sum(u)"<<std::endl;
    std::vector<double> vector_u;
    ahe->AHE_DEC(ahe->decryptor,*cipher_u,vector_u);
    double u = std::accumulate(vector_u.begin(),vector_u.end(),0.0);

    return u;

}
double client_dot_product_triplet_generation(std::vector<double> *vector_r){
    
    size_t n = ahe->slot_count;
    
    double _v[n];
    for (size_t i = 0; i < n; i++){
        _v[i] = rand()%N;
    }
    std::vector<double> vector_v(_v,_v+n);
    seal::Plaintext plain_v;
    ahe->AHE_CODE(vector_v,plain_v);

    sem_wait(&sem2);
    //receive(CLIENT,"[w]");
    //std::cout<< "comm: server === cipher_w ===> client"<<std::endl;

    //std::cout<< "client: r·[w]-v = [u]"<<std::endl;
    seal::Ciphertext cipher_u0;
    cipher_u = new seal::Ciphertext();
    ahe->AHE_MUL(*cipher_w,*vector_r,cipher_u0);
    ahe->evaluator->rescale_to_next_inplace(cipher_u0);
    cipher_u0.scale() = ahe->scale;
    seal::parms_id_type last_parms_id = cipher_u0.parms_id();
    ahe->evaluator->mod_switch_to_inplace(plain_v, last_parms_id);
    ahe->evaluator->sub_plain(cipher_u0,plain_v,(*cipher_u));

    //std::cout<< "comm: client === cipher_u ===> server"<<std::endl;
    
    //send(CLIENT,"[u]");
    sem_post(&sem1);

    //std::cout<< "client: v=sum(v)"<<std::endl;
    float v = std::accumulate(vector_v.begin(),vector_v.end(),0.0);
    return v;
}

/*
* conv1卷积，client生成X_C = R,并发送X_S = X-R
*/

void server_conv1_pre(){
    sem_wait(&sem2);
    receive(SERVER,"X_S");

    double w[25];
    std::vector<double> vectors_w[conv1_out_dims[0]];//16*(25*1)
    for (size_t i = 0; i < conv1_out_dims[0]; i++){
        for (size_t j = 0; j < 25; j++){
            w[j] = con1_0_weight_extend[i][j];
        }
        vectors_w[i] = std::vector<double>(w,w+25);
    }
    
    for (size_t i = 0; i < 16; i++){
        for (size_t j = 0; j < 496; j++){
            con1_ys_extend[i][j] = server_dot_product_triplet_generation(&vectors_w[i]);
        }
    }

}
void client_conv1_pre(){
    for (size_t i = 0; i < conv1_out_dims[0]; i++){
        for (size_t j = 0; j < conv1_out_dims[1]; j++){
            con1_xc_extend[i][j] = rand()/(RAND_MAX+0.0);
            con1_xs_extend[i][j] = con1_input_extend[i][j] - con1_xc_extend[i][j];
        }
    }

    send(CLIENT,"X_S");
    sem_post(&sem2);

    double v[25];
    std::vector<double> vectors_v[conv1_out_dims[1]];//496*25
    for (size_t j = 0; j < conv1_out_dims[1]; j++){//note the order 
    
        for (size_t i = 0; i < 25; i++){
            v[i] = con1_xc_extend[i][j];
        }
        vectors_v[j] = std::vector<double>(v,v+25);
    }
    
    for (size_t j = 0; j < 496; j++){//note the order 
        for (size_t i = 0; i < 16; i++){
            if((j+1)%10==0 || j+1==496){
                std::cout<<j+1<<"/496"<<std::endl;
            }
            con1_yc_extend[i][j] = client_dot_product_triplet_generation(&vectors_v[j]);
        }
    }

}



void server_conv1(){
    

}
void client_conv1(){
    

}

void test(){

    size_t ok = 0;
    int ret = 0;  
    pthread_t id1;  
    pthread_t id2;  
    sem_init(&sem1, 0, 0);  
    sem_init(&sem2, 0, 0);
    
    ahe = new AHE();
    if(ok)
    {
    Role client(ROLE_CLIENT, "workdir/client", "127.0.0.1", 22222);
    Role server(ROLE_SERVER, "workdir/server", "127.0.0.1", 11111);
    client.comm(server, "1.txt", "1.bak.txt");
    server.comm(client, "2.txt", "2.bak.txt");
    std::cout<<"___ comm ok______________________"<<std::endl;
    // AHE
    double x[] = {1.5, -2, 3};
    double x1[] = {3, 2, 1.5};
    std::vector<double> input1(x, x + 3);
    std::vector<double> input2(x1, x1 + 3);
    std::vector<double> output1, output2, output_add, output_mul, output_sub_plain;
    seal::Ciphertext cipher1, cipher2, cipher_add, cipher_mul, cipher_sub_plain;

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
    ahe->AHE_SUB_PLAIN(cipher_mul,input1,cipher_sub_plain,1);
    ahe->AHE_DEC(ahe->decryptor, cipher_sub_plain, output_sub_plain);

    std::cout << "input1: " << std::endl;
    print_vector(input1);
    std::cout << "output1: " << std::endl;
    print_vector(output1);
    std::cout << "input2: " << std::endl;
    print_vector(input2);
    std::cout << "output2: " << std::endl;
    print_vector(output2);

    std::cout << "output_add = [input1] + [input2]: " << std::endl;
    print_vector(output_add);
    std::cout << "output_mul = [input1] * input1: " << std::endl;
    print_vector(output_mul);
    std::cout << "output_sub_plain = [cipher_mul] - input1: " << std::endl;
    print_vector(output_sub_plain);

    std::cout<<"____ AHE ok_______________________"<<std::endl ;

    size_t n = ahe->slot_count;
    double w[n]={1,2,3},r[n]={1,2,3};
    std::vector<double> vector_w(w,w+3);
    std::vector<double> vector_r(r,r+3);
    th_t_dot3gen u_t = {&vector_w,0},v_t={&vector_r,0};
      
    
    pthread_create(&id1, NULL, (void *(*)(void *))server_dot_product_triplet_generation, (void*)&u_t);  
    pthread_create(&id2, NULL,(void *(*)(void *))client_dot_product_triplet_generation, (void*)&v_t);  
    pthread_join(id1, (void**)&u_t);  
    pthread_join(id2, (void**)&v_t);  
    double u = u_t.num;
    double v = v_t.num;
    std::cout << "w·r = "<< std::inner_product(vector_w.begin(),vector_w.end(),vector_r.begin(),0.0) <<std::endl;
    std::cout << "u+v = "<<u+v<<std::endl;
    std::cout<<"____ dot_product_triplet_generation ok_______________________"<<std::endl ;

    std::string model_path = "/home/dingyc/PPML/mywork/2PC/pytorch_test/models/cnn_mnist/mnist_net.pt";
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
    std::string model_path = "/home/dingyc/PPML/mywork/2PC/pytorch_test/models/cnn_mnist/mnist_net.pt";
    get_double_params(model_path);
    
    pthread_create(&id1, NULL, (void *(*)(void *))client_conv1_pre, NULL);  
    pthread_create(&id2, NULL,(void *(*)(void *))server_conv1_pre, NULL);  
    pthread_join(id1, NULL);  
    pthread_join(id2, NULL);
    std::cout<<"____ conv1_pre ok______________________"<<std::endl;
    
    /*
    th_t_conv_server s_t={(float**)con1_0_weight_extend,(float**)con1_xs_extend,NULL};
    th_t_conv_client c_t={(float**)con1_xc_extend};
    pthread_create(&id1, NULL, (void *(*)(void *))server_dot_product_triplet_generation, (void*)&s_t);  
    pthread_create(&id2, NULL,(void *(*)(void *))client_dot_product_triplet_generation, (void*)&c_t);  
    pthread_join(id1, (void**)&s_t);  
    pthread_join(id2, (void**)&c_t);  
    
    
    std::cout<<"____ conv ok______________________"<<std::endl;
    */

    sem_destroy(&sem1);  
    sem_destroy(&sem2);  


    delete ahe;
}

int main()
{

    test();
    return 0;
}