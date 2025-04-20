#pragma once
#include "Data.h"

class Linear_Regression{
public:
    Data weight;
    std::vector <float> losses;

    Linear_Regression(int theta_size);
    float Get_Error(Data& pred, Data& data);
    void Fit(Data& x, Data& y, float learning_rate = 0.01, int loop = 20);
};