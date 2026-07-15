#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class TarjanSCC {
private:
    int V;
    vector<vector<int>> adj;

    vector<int> disc;      // Discovery time
    vector<int> low;       // Lowest reachable discovery time
    vector<bool> inStack;
    stack<int> st;
    int timer;

    void dfs(int u) {
        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for (int v : adj[u]) {

            // Tree Edge
            if (disc[v] == -1) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }

            // Back Edge
            else if (inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        // Root of SCC
        if (disc[u] == low[u]) {
            cout << "SCC: ";

            while (true) {
                int node = st.top();
                st.pop();
                inStack[node] = false;

                cout << node << " ";

                if (node == u)
                    break;
            }

            cout << endl;
        }
    }

public:
    TarjanSCC(int vertices) {
        V = vertices;
        adj.resize(V);

        disc.assign(V, -1);
        low.assign(V, -1);
        inStack.assign(V, false);

        timer = 0;
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void findSCCs() {
        for (int i = 0; i < V; i++) {
            if (disc[i] == -1)
                dfs(i);
        }
    }
};

int main() {

    TarjanSCC g(6);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);

    g.addEdge(1, 3);

    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    cout << "Strongly Connected Components:\n";
    g.findSCCs();

    return 0;
}