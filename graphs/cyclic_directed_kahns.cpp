#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// Topological sort using Kahn's Algorithm
class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<int> sorted;
        int count = 0;

        // Convert edges to adjacency list
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);

        // Compute indegree of each vertex
        for (int u = 0; u < V; u++) {
            for (auto &v : adj[u])
                indegree[v]++;
        }

        // Enqueue vertices with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // Kahn's BFS loop
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            sorted.push_back(u);
            count++;

            for (auto &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        // Output cycle detection info
        if (count == V)
            cout << "No cycle" << endl;
        else
            cout << "Cycle detected" << endl;

        return sorted;
    }
};
