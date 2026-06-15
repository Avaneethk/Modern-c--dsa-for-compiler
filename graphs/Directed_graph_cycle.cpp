class Solution {
public:

bool iscycledfs(int u,vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& inRecursion)
 {
    visited[u]=true;
    inRecursion[u]=true;
    for(int& v:adj[u])
    {
        //if not visited check for cycle in DFS
        if(visited[v]== false && iscycledfs(v,adj,visited,inRecursion) )
        return true;
        else if(inRecursion[v]==true)
        {
            return true;
        }
        
    }
    
    inRecursion[u]=false;
    return false;
    
 }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<bool> visited(V,false);
        vector<bool> inRecursion(V,false);
        
        vector<vector<int>> adj(V);
        
        for(auto& e:edges)
        adj[e[0]].push_back(e[1]);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false && iscycledfs(i,adj,visited,inRecursion))
            return true;
             
        }
        return false;
       
    }
};

