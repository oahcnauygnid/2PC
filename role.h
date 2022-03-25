
#include<string>

#include<iostream>
using namespace std;

/*
* 通信
* （应使用protobuf+RPC，现忽略通信，以本地复制文件的形式进行交互）
*/
class Role{
public:
    int type;
    string ip;
    string workdir;
    int port;
    Role();
    ~Role(){}
    Role(int t,string w, string i, int p){
        type = t;
        workdir = w;
        ip = i;
        port = p;
    }

    void print(){
        cout << "test class method " + type <<endl;
    }


    void connect(Role role_dst){
    }
    void comm(Role role_dst,string file_src, string file_dst){
        connect(role_dst);
        string cmd = ("cp " + workdir+"/"+file_src +" "+ role_dst.workdir+"/"+file_dst);
        system(cmd.c_str());
        print();
    }

};
