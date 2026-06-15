
using namespace std;
bool isCycleUtil(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[v] = true;
  
    for (int i : adj[v])
    {
        if(i==parent) continue;
        
        if(visited[i]) return true;
       
        if (isCycleUtil(i, adj, visited, v))  return true; //recursive 
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++) //traverse through all the nodes 
    {
        if (!visited[u] && isCycleUtil(u, adj, visited, -1) )
        {
                return true;
        }
    }
    return false;
}

int main()
{
    int V = 5;
    vector<vector<int>> adj(5);
   
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
  	adj[0].push_back(3);
    adj[3].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
  
    if (isCycle(V, adj)) cout << "true" << endl;
    else cout << "false" << endl;
  
    return 0;
}
