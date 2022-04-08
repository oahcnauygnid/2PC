#include <iostream>
#include <fstream>
#include <string>
#include "protobuf_test.pb.h"

void test_protobuf(){
  protobuf_test::Protobuf_test proto;
  double d[] = {1,2,3,4};
  std::vector<double> data(d,d+4);
  proto.mutable_num()->Add(data.begin(),data.end());
  std::cout<<"ok"<<std::endl;
  


}


int main(int argc, char* argv[]) {
  test_protobuf();


  
  // Optional:  Delete all global objects allocated by libprotobuf.
  // ＠＠＠ ShutdownProtobufLibrary
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}