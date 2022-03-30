#include "torch/script.h"
#include <iostream>
#include <string>
using namespace std;

/* mnist cnn
name: con1.0.weight
size: [16, 1, 5, 5]
flatten: [400]
name: con1.0.bias
size: [16]
flatten: [16]
name: con2.0.weight
size: [32, 16, 5, 5]
flatten: [12800]
name: con2.0.bias
size: [32]
flatten: [32]
name: fc1.weight
size: [10, 1568]
flatten: [15680]
name: fc1.bias
size: [10]
flatten: [10]
*/
float con1_0_weight[16][1][5][5];
float con1_0_bias[16];
float con2_0_weight[32][16][5][5];
float con2_0_bias[32];
float fc1_weight[10][1568];
float fc1_bias[10];

void get_double_modules(torch::jit::Module module) {
    int i = 0;
    for(auto params: module.named_parameters()){
        auto data = params.value.data();
        switch (i)
        {
        case 0:
            for (size_t i0 = 0; i0 < 16; i0++)
                for (size_t i1 = 0; i1 < 1; i1++)
                    for (size_t i2 = 0; i2 < 5; i2++)
                        for (size_t i3 = 0; i3 < 5; i3++)
                            con1_0_weight[i0][i1][i2][i3] = data[i0][i1][i2][i3].item().toFloat();
            break;
        case 1:
            for (size_t i0 = 0; i0 < 16; i0++)
                con1_0_bias[i0] = data[i0].item().toFloat();
            break;
        case 2:
            for (size_t i0 = 0; i0 < 32; i0++)
                for (size_t i1 = 0; i1 < 16; i1++)
                    for (size_t i2 = 0; i2 < 5; i2++)
                        for (size_t i3 = 0; i3 < 5; i3++)
                            con2_0_weight[i0][i1][i2][i3] = data[i0][i1][i2][i3].item().toFloat();
            break;
        case 3:
            for (size_t i0 = 0; i0 < 32; i0++)
                    con2_0_bias[i0] = data[i0].item().toFloat();
            break;
        case 4:
            for (size_t i0 = 0; i0 < 10; i0++)
                for (size_t i1 = 0; i1 < 1568; i1++)
                    fc1_weight[i0][i1] = data[i0][i1].item().toFloat();
            break;
        case 5:
            for (size_t i0 = 0; i0 < 10; i0++)
                fc1_bias[i0] = data[i0].item().toFloat();
            break;
        default:
            break;
        }
        i++;
    }
}

int main() {
    
    string model = "/home/dingyc/PPML/mywork/2PC/pytorch_test/models/cnn_mnist/mnist_net10+20.pt";
    torch::jit::Module net = torch::jit::load(model.c_str());
    get_double_modules(net);
    cout<< "get_double_modules ok" << endl;
    

}