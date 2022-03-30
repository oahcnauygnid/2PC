#pragma once
#include<string>

#include<iostream>

/*
* 通信
* （应使用protobuf+RPC，现忽略通信，以本地复制文件的形式进行交互）
*/
class Role{
public:
    int type;
    std::string ip;
    std::string workdir;
    int port;
    Role();
    ~Role(){}
    Role(int t,std::string w, std::string i, int p){
        type = t;
        workdir = w;
        ip = i;
        port = p;
    }

    void print(){
        std::cout << "test class method " + type <<std::endl;
    }


    void connect(Role role_dst){
    }
    void comm(Role role_dst, std::string file_src, std::string file_dst){
        connect(role_dst);
        std::string cmd = ("cp " + workdir+"/"+file_src +" "+ role_dst.workdir+"/"+file_dst);
        system(cmd.c_str());
        Role::print();
    }

};
