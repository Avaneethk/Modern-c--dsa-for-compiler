class Solution {
  public:
    void dfsFill(int u, vector<vector<int>> &adj, vector<bool>& visited, stack<int>& st) {
        visited[u] = true;
        for (int &v : adj[u]) {
            if (!visited[v]) {
                dfsFill(v, adj, visited, st);
            }
        }
        st.push(u);
    }

    void dfsTraversal(int u, vector<vector<int>>& adjReversed, vector<bool>& visited) {
        visited[u] = true;
        for (int &v : adjReversed[u]) {
            if (!visited[v]) {
                dfsTraversal(v, adjReversed, visited);
            }
        }
    }

    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        stack<int> st;
        vector<bool> visited(V, false);

        // First DFS pass to fill the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsFill(i, adj, visited, st);
            }
        }

        // Reverse the graph
        vector<vector<int>> adjReverse(V);
        for (int u = 0; u < V; u++) {
            for (auto &v : adj[u]) {
                adjReverse[v].push_back(u);
            }
        }

        // Second DFS pass on the reversed graph
        visited = vector<bool>(V, false);
        int countScc = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!visited[node]) {
                dfsTraversal(node, adjReverse, visited);
                countScc++;
            }
        }

        return countScc; 
    }
};
