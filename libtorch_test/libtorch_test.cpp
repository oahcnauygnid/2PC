#include "torch/torch.h"

#include <iostream>
using namespace std;

int main() {
    
    torch::Tensor tensor = torch::eye(3);
    cout << tensor << endl;
    torch::jit::script::Module module = torch::jit::load(argv[1]);


}