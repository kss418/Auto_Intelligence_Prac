#pragma once
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

class Data{
public:
    std::vector<std::vector<float>> v;
    int y = 0, x = 0;

    Data(){}
    Data(int y, int x);
    Data Transpose();

    static Data Ones(int y, int x);
    static Data Zeros(int y, int x);
    static Data Concatenate(const Data& a, const Data& b);
    static float Sum(const Data& a);
    static Data Log(const Data& a);
};

Data operator * (const Data& a, const Data& b);
Data operator * (const float& a, const Data& b);

Data operator - (const float& a, const Data& b);
Data operator - (const Data& a, const float& b);
Data operator - (const Data& a, const Data& b);

Data operator + (const Data& a, const float& b);
Data operator + (const Data& a, const Data& b);
Data operator + (const Data& a, const Data& b);
