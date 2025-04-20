#pragma once
#include "Data.h"
#include <random>

class K_Means_Clustering{
public:
    std::vector <float> losses;

    K_Means_Clustering(size_t k);
    float Distance(const Data& a, const Data& b);
    float Get_Error(const Data& x);
    Data Get_Centroid(const Data& a);

    void Get_Random_Centroid(const Data& x);
    void Get_Closest_Cluster(const Data& x);
    void Get_Labels(const Data& x);
    void Get_New_Centroid(const Data& x);
    
    void Fit(const Data& x, int loop = 20);
private:
    size_t k;
    bool changed = 0;

    std::vector<Data> centroids;
    std::vector<int> labels;
    std::random_device rd;
    std::mt19937 key;
    std::uniform_int_distribution<int> random;
    std::vector<std::vector<Data>> clusters;
};
