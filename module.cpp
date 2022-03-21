/*
Created by dingyc.
2022.
*/

#include<string>
#include<iostream>
#include "seal/seal.h"

#define MAX_LEN 4096

using namespace std;

#define ROLE_CLIENT 0x00
#define ROLE_SERVER 0x01



class Role{


public:
    string name;
    string ip;
    string workdir;
    int port;
    Role();
    ~Role(){}
    Role(string n,string w, string i, int p){
        name = n;
        workdir = w;
        ip = i;
        port = p;
    }

    void print(){
        cout << "test class method " + name <<endl;
    }

    /*
    * 通信
    * （现忽略通信，以本地复制文件的形式进行交互）
    */
    void connect(Role role_dst){
    }
    void comm(Role role_dst,string file_src, string file_dst){
        connect(role_dst);
        string cmd = ("cp " + workdir+"/"+file_src +" "+ role_dst.workdir+"/"+file_dst);
        system(cmd.c_str());
        print();
    }

};

/*
* 生成三元组（HE-based）
*/
void dot_product_triplet_generation(Role role){



}



int main(){
    Role client("client","workdir/client","127.0.0.1",22222);
    Role server("server","workdir/server","127.0.0.1",11111);
    client.comm(server,"1.txt","1.bak.txt");

    return 0;
}