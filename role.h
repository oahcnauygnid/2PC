
#include<string>

#include<iostream>
using namespace std;

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
