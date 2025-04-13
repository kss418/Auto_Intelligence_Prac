#include <iostream>
#include <vector>

class Data{
public:
    std::vector<std::vector<float>> v;
    Data Transpose(){
        int y = v.size(), x = v[0].size();
        Data ret; ret.v.resize(x, std::vector<float>(y));

        for(int i = 0;i < x;i++){
            for(int j = 0;j < y;j++) ret.v[i][j] = v[j][i];
        }

        return ret;
    }
};

Data operator * (const Data& a, const Data& b){
    int ay = a.v.size(), ax = a.v[0].size();
    int by = b.v.size(), bx = b.v[0].size();

    Data ret; ret.v.resize(ay, std::vector<float>(bx));
    for(int i = 0;i < ay;i++){
        for(int j = 0;j < bx;j++){
            for(int k = 0;k < ax;k++) ret.v[i][j] += a.v[i][k] * b.v[k][j];
        }
    }

    return ret;
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
    Data a, b, c;
    a.v = {{5, 3}, {2, 4}};
    b.v = {{2, 3}, {3, 4}};

    c = a.Transpose();
    for(auto& i : c.v){
        for(auto& j : i) std::cout << j << " ";
        std::cout << "\n";
    }

    return 0;
}