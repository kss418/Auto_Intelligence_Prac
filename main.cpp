#include <iostream>
#include "include/Data.h"
#include "include/Linear_Regression.h"

int main(){
    Data a(8, 1), b(8, 1);
    a.v = {{1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}};
    b.v = {{2}, {5}, {9}, {12}, {14}, {17}, {21}, {23}};

    Linear_Regression model;
    model.Fit(a, b);
    
    for(auto& i : model.losses) std::cout << i << " ";
    return 0;
}