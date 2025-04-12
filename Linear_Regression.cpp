#include <iostream>
#include <vector>

class Data{
public:
    std::vector<std::vector<float>> v;
    Data Transpose(Data& data){

    }
};

Data operator * (const Data& a, const Data& b){
    int ax = a.v.size(), ay = a.v[0].size();
    int bx = b.v.size(), by = b.v[0].size();

    Data ret;
}
 

class Linear_Regression{
    public:


   
    float F(float w, float x){
        return w * x;
    }

    float Get_Error(float w, float x, float y){
        float ret = F(w, x) - y;
        return ret * ret;
    }

    float Get_Error(Data& data, Data& w){

    }

    void Fit(Data& data, Data& w, int loop = 1000){
        while(loop--){
            float error = Get_Error(data, w);
            
        }

    }
};


int main(){
    Linear_Regression model;

    return 0;
}