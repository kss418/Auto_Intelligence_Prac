#include "Data.h"

class DBSCAN{
public:
    DBSCAN(int min_count, float eps);
    float Get_Error(const Data& x);
    float Distance(const Data& a, const Data& b);
    void Fit(const Data& x);
private:
    std::vector<Data> centroids;
    std::vector<int> labels;
    std::vector<std::vector<Data>> clusters;
    
    int min_count;
    float eps;
};