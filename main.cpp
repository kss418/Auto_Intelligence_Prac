#include <iostream>
#include "include/Data.h"
#include "include/Linear_Regression.h"
#include "include/Logistic_Regression.h"

int main(){
    Data a(8, 1), b(8, 1);
    a.v = {{0.1}, {0.5}, {0.8}, {1.0}, {1.3}, {1.7}, {2.0}, {2.5}, {3.0}, {3.5}};
    b.v = {{0}, {0}, {0}, {0}, {0}, {1}, {1}, {1}, {1}, {1}};

    Logistic_Regression model;
    model.Fit(a, b);
    
    for(auto& i : model.losses) std::cout << i << " ";
    return 0;
}