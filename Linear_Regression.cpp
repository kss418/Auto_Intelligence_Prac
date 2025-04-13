#include <iostream>
#include <vector>
#include <string>
#include "Data.h"
 
std::vector <float> losses;
class Linear_Regression{
public:
    Data weight;

    Linear_Regression(){
        weight = Data(1, 1);
    }

    float Get_Error(Data& pred, Data& data){
        Data diff = pred - data;
        float sum = 0;
        for(auto& i : diff.v){
            for(auto& j : i) sum += j * j;
        }
        return sum / (2 * pred.y);
    }

    void Fit(Data& x, Data& y, float learning_rate = 0.01, int loop = 20){
        while(loop--){
            Data y_hat = x * weight;
            float loss = Get_Error(y_hat, y);
            
            Data gradients = (1.0f / y.y) * x.Transpose() * (y_hat - y);
            weight = weight - (learning_rate * gradients);

            losses.push_back(loss);
        }
    }
};


int main(){
    Data a(8, 1), b(8, 1);
    a.v = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}};
    b.v = {{2}, {5}, {9}, {12}, {14}, {17}, {21}, {23}};

    Linear_Regression model;
    model.Fit(a, b);
    
    for(auto& i : losses) std::cout << i << " ";
    return 0;
}