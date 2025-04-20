#include <iostream>
#include "include/Data.h"
#include "include/Linear_Regression.h"
#include "include/Logistic_Regression.h"
#include "include/K_Means_Clustering.h"
#include "include/DBSCAN.h"

int main(){
    DBSCAN model(6, 0.4);
    Data x(100, 2);
    x.v = {
        // Cluster 1 (around (1, 1))
        {1.0f, 1.0f}, {1.2f, 0.9f}, {0.8f, 1.1f}, {1.1f, 1.3f}, {0.9f, 0.8f},
        {1.3f, 1.2f}, {0.7f, 0.9f}, {1.2f, 1.1f}, {0.9f, 1.3f}, {1.0f, 0.7f},
        {1.1f, 0.8f}, {0.8f, 0.7f}, {0.9f, 1.0f}, {1.3f, 0.9f}, {1.0f, 1.2f},
        {0.7f, 1.1f}, {1.2f, 1.3f}, {0.8f, 1.2f}, {1.1f, 0.9f}, {0.9f, 0.9f},
    
        // Cluster 2 (around (5, 5))
        {5.0f, 5.0f}, {5.2f, 5.1f}, {5.1f, 5.3f}, {4.9f, 5.2f}, {5.3f, 4.9f},
        {4.8f, 5.0f}, {5.2f, 4.8f}, {5.1f, 5.1f}, {4.9f, 4.8f}, {5.0f, 5.2f},
        {5.3f, 5.0f}, {5.0f, 4.9f}, {4.7f, 5.1f}, {5.2f, 5.3f}, {4.9f, 5.1f},
        {5.1f, 4.7f}, {5.0f, 5.1f}, {5.3f, 5.2f}, {4.8f, 5.3f}, {5.1f, 4.9f},
    
        // Cluster 3 (around (8, 1))
        {8.0f, 1.0f}, {8.2f, 1.1f}, {7.9f, 1.2f}, {8.1f, 0.9f}, {7.8f, 1.0f},
        {8.3f, 1.2f}, {7.7f, 0.8f}, {8.0f, 1.3f}, {8.2f, 0.7f}, {7.9f, 0.9f},
        {8.1f, 1.1f}, {8.0f, 0.8f}, {7.8f, 1.3f}, {8.2f, 1.0f}, {8.0f, 1.2f},
        {7.7f, 1.1f}, {8.3f, 0.9f}, {7.9f, 1.1f}, {8.1f, 0.8f}, {7.8f, 0.9f},
    
        // Noise points
        {2.5f, 7.0f}, {6.0f, 2.0f}, {3.0f, 3.0f}, {7.0f, 7.0f}, {1.0f, 7.0f},
        {2.0f, 2.0f}, {6.5f, 6.5f}, {3.5f, 5.0f}, {0.5f, 8.0f}, {9.0f, 6.0f},
        {2.0f, 8.0f}, {4.0f, 1.0f}, {5.5f, 7.5f}, {6.0f, 1.0f}, {1.0f, 5.5f},
        {3.0f, 6.5f}, {4.5f, 0.5f}, {8.5f, 4.5f}, {7.0f, 2.5f}, {2.5f, 1.5f},
    
        // 추가로 더 퍼뜨린 Noise (10개)
        {7.0f, 5.0f}, {2.0f, 5.5f}, {6.0f, 6.0f}, {8.0f, 7.0f}, {3.5f, 7.5f},
        {4.0f, 6.0f}, {2.5f, 4.0f}, {7.5f, 1.5f}, {8.5f, 1.0f}, {1.5f, 2.5f}
    };

    model.Fit(x);
    for(auto& i : model.labels) std::cout << i << " ";
    
    
    
    return 0;
}