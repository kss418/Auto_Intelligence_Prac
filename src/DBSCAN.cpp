#include "../include/DBSCAN.h"

DBSCAN::DBSCAN(int min_count, float eps) : min_count(min_count), eps(eps) {}

float DBSCAN::Distance(const std::vector<float>& a, const std::vector<float>& b){
    float ret = 0;
    for(size_t i = 0;i < a.size();i++){
        float diff = a[i] - b[i];
        ret += diff * diff;
    }
    return std::sqrt(ret);
}

void DBSCAN::Fit(const Data& x){
    labels.resize(x.x, -1);
    for(size_t i = 0;i < x.x;i++){
        if(labels[i] != -1) continue;
        std::vector <int> neighbors;
        for(size_t j = 0;j < x.x;j++){
            if(Distance(x.v[i], x.v[j]) > eps) continue;
            neighbors.push_back(j);
        }

        if(neighbors.size() < min_count) continue;
        labels[i] = cluster_count;

        size_t index = 0;
        while(index < neighbors.size()){
            int num = neighbors[index];
            if(labels[num] != -1){ index++; continue; }
            labels[num] = cluster_count;

            for(int j = 0;j < x.x;j++){
                if(labels[j] != -1) continue;
                if(Distance(x.v[i], x.v[j]) > eps) continue;
                neighbors.push_back(j);
            }
            index++;
        }
        cluster_count++;
    }
}