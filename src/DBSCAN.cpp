#include "../include/DBSCAN.h"

DBSCAN::DBSCAN(int min_count, float eps) : min_count(min_count), eps(eps) {}

float DBSCAN::Distance(const Data& a, const Data& b){
    float ret = 0;
    for(size_t i = 0;i < a.x;i++){
        float diff = a.v[0][i] - b.v[0][i];
        ret += diff * diff;
    }
    return ret;
}