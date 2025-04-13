#include <iostream>
#include <vector>
#include <string>
#include "../include/Linear_Regression.h"
    
Linear_Regression::Linear_Regression(){
    weight = Data(1, 1);
}
    
float Linear_Regression::Get_Error(Data& pred, Data& data){
    Data diff = pred - data;
    float sum = 0;
    for(auto& i : diff.v){
        for(auto& j : i) sum += j * j;
    }
    return sum / (2 * pred.y);
}
    
void Linear_Regression::Fit(Data& x, Data& y, float learning_rate, int loop){
    while(loop--){
        Data y_hat = x * weight;
        float loss = Get_Error(y_hat, y);
                
        Data gradients = (1.0f / y.y) * x.Transpose() * (y_hat - y);
        weight = weight - (learning_rate * gradients);
    
        losses.push_back(loss);
    }
}
