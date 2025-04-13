#pragma once
#include "Data.h"

class Logistic_Regression{
public:
    Data weight;
    std::vector <float> losses;

    Logistic_Regression();
    Data Sigmoid(Data& z);
    float Get_Error(Data& pred, Data& data);
    void Fit(Data& x, Data& y, float learning_rate = 0.01, int loop = 20);
};