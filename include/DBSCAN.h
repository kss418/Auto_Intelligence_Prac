#pragma once
#include "Data.h"

class DBSCAN{
public:
    DBSCAN(int min_count, float eps);
    float Distance(const std::vector<float>& a, const std::vector<float>& b);
    void Fit(const Data& x);
    std::vector<int> labels;
private:
    std::vector<std::vector<Data>> clusters;

    int min_count, cluster_count = 0;
    float eps;
};