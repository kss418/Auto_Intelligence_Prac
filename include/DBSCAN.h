#pragma once
#include "Data.h"

class DBSCAN{
public:
    DBSCAN(int min_count, float eps);
    float Silhouette_Score(const Data& x);
    float Distance(const std::vector<float>& a, const std::vector<float>& b);
    void Fit(const Data& x);
private:
    std::vector<int> labels;
    std::vector<std::vector<Data>> clusters;

    int min_count, cluster_count = 0;
    float eps;
};