#include <iostream>
#include "include/Data.h"
#include "include/Linear_Regression.h"
#include "include/Logistic_Regression.h"

int main(){
    Data a(10, 1), b(10, 1);
    a.v = {{0.1}, {0.5}, {0.8}, {1.0}, {1.3}, {1.7}, {2.0}, {2.5}, {3.0}, {3.5}};
    a = a.Concatenate(a.Ones(10, 1), a);
    b.v = {{0}, {0}, {0}, {0}, {0}, {1}, {1}, {1}, {1}, {1}};

    Logistic_Regression model(2);
    model.Fit(a, b, 0.1, 5000);

    for(auto& i : model.Sigmoid(a * model.weight).v){
        for(auto& j : i) std::cout << j << " ";
    }
    
    return 0;
}