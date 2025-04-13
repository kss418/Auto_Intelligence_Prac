#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "../include/Logistic_Regression.h"
    
Logistic_Regression::Logistic_Regression(){
    weight = Data(1, 1);
}

Data Logistic_Regression::Sigmoid(Data& z){
    Data ret(z.y, z.x);
    
}
    
float Logistic_Regression::Get_Error(Data& pred, Data& data){
    
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
