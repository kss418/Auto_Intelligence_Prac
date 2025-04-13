#include "../include/Data.h"
#include <string>
#include <iostream>
#include <cmath>

Data::Data(int y, int x){ 
    v.resize(y, std::vector<float>(x, 0.0f)); 
    this->y = y; this->x = x;
}

Data Data::Transpose(){
    Data ret(x, y);
    for(int i = 0;i < x;i++){
        for(int j = 0;j < y;j++) ret.v[i][j] = v[j][i];
    }
    return ret;
}

Data Data::Ones(int y, int x){
    Data ret(y, x);
    for(auto& i : ret.v){
        for(auto& j : i) j = 1;
    }
    return ret;
}

Data Data::Zeros(int y, int x){
    Data ret(y, x);
    for(auto& i : ret.v){
        for(auto& j : i) j = 0;
    }
    return ret;
}

Data Data::Concatenate(const Data& a, const Data& b){
    Data ret(a.y, a.x + b.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < a.x;j++) ret.v[i][j] = a.v[i][j];
        for(int j = 0;j < b.x;j++) ret.v[i][j + a.x] = b.v[i][j];
    }
    return ret;
}
    
float Data::Sum(const Data& a){
    float ret = 0;
    for(auto& i : a.v){
        for(auto& j : i) ret += j;
    }
    return ret;
}

Data operator * (const Data& a, const Data& b){
    if (a.x != b.y) {
        throw std::runtime_error("A is" + std::to_string(a.y) + " * " + std::to_string(a.x) +
            "B is " + std::to_string(b.y) + " * " + std::to_string(b.x)
        );
    }

    Data ret(a.y, b.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < b.x;j++){
            for(int k = 0;k < a.x;k++) ret.v[i][j] += a.v[i][k] * b.v[k][j];
        }
    }
    return ret;
}

Data operator * (const float& a, const Data& b){
    Data ret(b.y, b.x);
    for(int i = 0;i < b.y;i++){
        for(int j = 0;j < b.x;j++) ret.v[i][j] = a * b.v[i][j];
    }
    return ret;
}

Data operator - (const Data& a, const Data& b){
    Data ret(a.y, a.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < b.x;j++) ret.v[i][j] = a.v[i][j] - b.v[i][j];
    }
    return ret;
}

Data operator - (const float& a, const Data& b){
    Data ret(b.y, b.x);
    for(int i = 0;i < b.y;i++){
        for(int j = 0;j < b.x;j++) ret.v[i][j] = a - b.v[i][j];
    }
    return ret;
}

Data operator - (const Data& a, const float& b){
    Data ret(a.y, a.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < a.x;j++) ret.v[i][j] = a.v[i][j] - b;
    }
    return ret;
}

Data operator + (const Data& a, const Data& b){
    Data ret(a.y, a.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < b.x;j++) ret.v[i][j] = a.v[i][j] + b.v[i][j];
    }
    return ret;
}

Data operator + (const float& a, const Data& b){
    Data ret(b.y, b.x);
    for(int i = 0;i < b.y;i++){
        for(int j = 0;j < b.x;j++) ret.v[i][j] = a + b.v[i][j];
    }
    return ret;
}

Data operator + (const Data& a, const float& b){
    Data ret(a.y, a.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < a.x;j++) ret.v[i][j] = a.v[i][j] + b;
    }
    return ret;
}

Data Data::Log(const Data& a){
    Data ret(a.y, a.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < a.x;j++) ret.v[i][j] = std::log(a.v[i][j]);
    }
    return ret;
}
