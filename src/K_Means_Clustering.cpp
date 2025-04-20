#include "../include/K_Means_Clustering.h"

K_Means_Clustering::K_Means_Clustering(size_t k) : k(k), key(rd()), random(0, 0) {
    clusters.resize(k);
}

float K_Means_Clustering::Distance(const Data& a, const Data& b) {
    float ret = 0;
    for (size_t i = 0; i < a.x; i++) { 
        float diff = a.v[0][i] - b.v[0][i];
        ret += diff * diff;
    }
    return std::sqrt(ret);
}

Data K_Means_Clustering::Get_Centroid(const Data& a) {
    if (a.v.empty()) return Data(0, 0);

    Data ret = Data(1, a.x);
    for (size_t i = 0; i < a.y; i++) { 
        for (size_t j = 0; j < a.x; j++) { 
            ret.v[0][j] += a.v[i][j];
        }
    }

    for (size_t j = 0; j < a.x; j++) ret.v[0][j] /= a.y; 
    return ret;
}

float K_Means_Clustering::Get_Error(const Data& x){
    float ret = 0;
    for(size_t i = 0;i < x.y;i++){
        Data now(1, x.x);
        for(size_t j = 0;j < x.x;j++){
            now.v[0][j] = x.v[i][j];
        }

        int cluster_id = labels[i];
        ret += Distance(now, centroids[cluster_id]);
    }
    return std::sqrt(ret);
}

void K_Means_Clustering::Get_Random_Centroid(const Data& x){
    std::vector<bool> use(x.y, 0); 
    while (centroids.size() < k) {
        int index = random(key);
        if (use[index]) continue;
        use[index] = 1;

        Data now(1, x.x);
        for (size_t i = 0; i < x.x; i++) {
            now.v[0][i] = x.v[index][i];
        }
        centroids.push_back(now);
    }
}

void K_Means_Clustering::Get_Closest_Cluster(const Data& x){
    for(size_t i = 0;i < x.y;i++){
        Data now(1, x.x);
        for(size_t j = 0;j < x.x;j++){
            now.v[0][j] = x.v[i][j];
        }

        float min_dist = Distance(now, centroids[0]);
        int best_cluster = 0;
        for(size_t j = 1;j < k;j++){
            float dist = Distance(now, centroids[j]);
            if(dist >= min_dist) continue;
            min_dist = dist; best_cluster = j;
        }

        if(labels[i] == best_cluster) continue;
        changed = 1; labels[i] = best_cluster;
    }
}

void K_Means_Clustering::Get_Labels(const Data& x){
    for(size_t i = 0;i < x.y;i++){
        Data now(1, x.x);
        for(size_t j = 0;j < x.x;j++){
            now.v[0][j] = x.v[i][j];
        }
        clusters[labels[i]].push_back(now);
    }
}

void K_Means_Clustering::Get_New_Centroid(const Data& x){
    for(size_t j = 0;j < k;j++){
        if(clusters[j].empty()) continue;
        Data now(clusters[j].size(), x.x);
        for(size_t r = 0;r < clusters[j].size();r++){
            for(size_t c = 0;c < x.x;c++){
                now.v[r][c] = clusters[j][r].v[0][c];
            }
        }
        centroids[j] = Get_Centroid(now);
    }
}

void K_Means_Clustering::Fit(const Data& x, int loop) {
    random.param(std::uniform_int_distribution<int>::param_type(0, x.y - 1));
    Get_Random_Centroid(x);

    labels.resize(x.y, 0);
    while(loop--){
        changed = 0;
        for(auto& cluster : clusters) cluster.clear();

        Get_Closest_Cluster(x);
        Get_Labels(x);
        Get_New_Centroid(x);

        losses.push_back(Get_Error(x));
        if(!changed) break;
    }
}

Data K_Means_Clustering::Predict(const Data& x){
    if(centroids.empty()) return Data(0, 0);

    float min_dist = Distance(x, centroids[0]);
    int best_cluster = 0;

    for(size_t i = 1;i < k;i++){
        float dist = Distance(x, centroids[i]);
        if(dist >= min_dist) continue;
        min_dist = dist; best_cluster = i;
    }

    return centroids[best_cluster];
}