#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../include/Logistic_Regression.h"
    
Logistic_Regression::Logistic_Regression(){
    weight = Data(1, 1);
}

float Logistic_Regression::Sigmoid(float& z){
    return (1.0f / (1.0f + std::exp(-z)));
}

Data Logistic_Regression::Sigmoid(Data z){
    Data ret(z.y, z.x);
    for(int i = 0;i < z.y;i++){
        for(int j = 0;j < z.x;j++) ret.v[i][j] = Sigmoid(z.v[i][j]);
    }
    return ret;
}
    
float Logistic_Regression::Get_Error(Data& pred, Data& data){
    float eps = 1e-8;
    return (-1.0 / pred.y) * Data::Sum(data * Data::Log(pred + eps) + (1 - data) * Data::Log(1 - pred + eps));
}
    
void Logistic_Regression::Fit(Data& x, Data& y, float learning_rate, int loop){
    while(loop--){
        Data y_hat = Sigmoid(x * weight);
        float loss = Get_Error(y_hat, y);
                
        Data gradients = (1.0f / y.y) * x.Transpose() * (y_hat - y);
        weight = weight - (learning_rate * gradients);
    
        losses.push_back(loss);
    }
}
