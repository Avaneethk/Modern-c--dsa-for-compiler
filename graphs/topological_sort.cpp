#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void dfs(int u, vector<bool>& visited, stack<int>& s, vector<vector<int>>& adj) {
        visited[u] = true;

        for (int& x : adj[u]) {
            if (!visited[x]) {
                dfs(x, visited, s, adj);
            }
        }

        // Push after visiting all children (post-order)
        s.push(u);
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<bool> visited(V, false);
        vector<int> sorted;
        stack<int> s;
        vector<vector<int>> adj(V);

        // Build adjacency list from edge list
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

        // Run DFS from all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, s, adj);
            }
        }

        // Pop elements from stack to get topological sort
        while (!s.empty()) {
            sorted.push_back(s.top());
            s.pop();
        }

        return sorted;
    }
};
