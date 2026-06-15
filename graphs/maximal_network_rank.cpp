#include <iostream>
#include <vector>
using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    vector<vector<int>> adj(n, vector<int>(n, 0)); // 2D adjacency matrix initialized to 0 
    vector<int> degree(n, 0); // Degree of each node

    // Build the adjacency matrix and degrees
    for (auto& road : roads) {
        int u = road[0];
        int v = road[1];
        adj[u][v] = 1;
        adj[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }

    int maxRank = 0;

    // Check all unique pairs of cities
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int rank = degree[i] + degree[j];
            if (adj[i][j]) {
                rank--; // subtract one if directly connected
            }
            maxRank = max(maxRank, rank);
        }
    }

    return maxRank;
}

int main() {
    int n = 5;
    vector<vector<int>> roads = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {2, 4}
    };

    cout << "Maximal Network Rank: " << maximalNetworkRank(n, roads) << endl;

    return 0;
}
