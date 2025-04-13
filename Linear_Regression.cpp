#include <iostream>
#include <vector>

class Data{
public:
    std::vector<std::vector<float>> v;
    int y = 0, x = 0;

    Data(){}
    Data(int y, int x){ 
        v.resize(y, std::vector<float>(x)); 
        this->y = y; this->x = x;
    }

    Data Transpose(){
        Data ret(y, x);
        for(int i = 0;i < x;i++){
            for(int j = 0;j < y;j++) ret.v[i][j] = v[j][i];
        }

        return ret;
    }

    static Data Ones(int y, int x){
        Data ret(y, x);
        for(auto& i : ret.v){
            for(auto& j : i) j = 1;
        }
        return ret;
    }

    static Data Zeros(int y, int x){
        Data ret(y, x);
        for(auto& i : ret.v){
            for(auto& j : i) j = 1;
        }
        return ret;
    }

    static Data Concatenate(Data& a, Data& b){
        Data ret(a.y, a.x + b.x);
        for(int i = 0;i < a.y;i++){
            for(int j = 0;j < a.x;j++) ret.v[i][j] = a.v[i][j];
            for(int j = 0;j < b.x;j++) ret.v[i][j + a.x] = b.v[i][j];
        }
        return ret;
    }
};

Data operator * (const Data& a, const Data& b){
    Data ret(a.y, b.x);
    for(int i = 0;i < a.y;i++){
        for(int j = 0;j < b.x;j++){
            for(int k = 0;k < a.x;k++) ret.v[i][j] += a.v[i][k] * b.v[k][j];
        }
    }

    return ret;
}
 

class Linear_Regression{
public:
    Data weight;

    Linear_Regression(){
        weight.v.resize(5, std::vector<float>(5));
    }

    float F(float w, float x){
        return w * x;
    }

    float Get_Error(float w, float x, float y){
        float ret = F(w, x) - y;
        return ret * ret;
    }

    float Get_Error(Data& data, Data& weight){

    }

    void Fit(Data& data, int loop = 1000){
        while(loop--){
            float error = Get_Error(data, weight);
            
        }

    }
};


int main(){
    Data a(2, 2), b(2, 2);
    a.v = {{5, 3}, {2, 4}};
    b.v = {{2, 3}, {3, 4}};

    Data c = Data::Concatenate(a, b);
    for(auto& i : c.v){
        for(auto& j : i) std::cout << j << " ";
        std::cout << "\n";
    }

    return 0;
}