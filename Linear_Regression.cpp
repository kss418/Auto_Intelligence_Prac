#include <iostream>
#include <vector>

class Data{
public:
    std::vector<std::vector<float>> v;
    int y = 0, x = 0;

    Data(){}
    Data(int y, int x){ 
        v.resize(y, std::vector<float>(x, 0.0f)); 
        this->y = y; this->x = x;
    }

    Data Transpose(){
        Data ret(x, y);
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
            for(auto& j : i) j = 0;
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
    
    static float sum(Data& a){
        float ret = 0;
        for(auto& i : a.v){
            for(auto& j : i) ret += j;
        }
        return ret;
    }
};

Data operator * (const Data& a, const Data& b){
    if (a.x != b.y) {
        throw std::runtime_error("Matrix dimension mismatch in operator*");
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
 
std::vector <float> losses;
class Linear_Regression{
public:
    Data weight;

    Linear_Regression(){
        weight = Data(1, 1);
    }

    float Get_Error(Data& pred, Data& data){
        Data diff = pred - data;
        float sum = 0;
        for(auto& i : diff.v){
            for(auto& j : i) sum += j * j;
        }
        return sum / (2 * pred.y);
    }

    void Fit(Data& x, Data& y, float learning_rate = 0.01, int loop = 20){
        while(loop--){
            Data y_hat = x * weight;
            float loss = Get_Error(y_hat, y);
            
            Data gradients = (1.0f / y.y) * x.Transpose() * (y_hat - y);
            weight = weight - (learning_rate * gradients);

            losses.push_back(loss);
        }
    }
};


int main(){
    Data a(8, 1), b(8, 1);
    a.v = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}};
    b.v = {{2}, {5}, {9}, {12}, {14}, {17}, {21}, {23}};

    Linear_Regression model;
    model.Fit(a, b);
    
    for(auto& i : losses) std::cout << i << " ";
    return 0;
}