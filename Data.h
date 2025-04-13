#include <iostream>
#include <vector>
#include <string>

class Data{
public:
    std::vector<std::vector<float>> v;
    int y = 0, x = 0;

    Data(){}
    Data(int y, int x);
    Data Transpose();

    static Data Ones(int y, int x);
    static Data Zeros(int y, int x);
    static Data Concatenate(Data& a, Data& b);
    static float sum(Data& a);
};

Data operator * (const Data& a, const Data& b);
Data operator * (const float& a, const Data& b);
Data operator - (const Data& a, const Data& b);
