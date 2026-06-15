#include <vector>
#include <stack>
using namespace std;

//Topological sort using kahn's algorithm
//get the indegree
//create a queue start push elements with indegree 0 
//move this queue to vector and return vector

class Solution {
public:


    vector<int> topoSort(int V, vector<vector<int>>& edges) {
       
        vector<vector<int>> adj(V);
        vector<int> indegree(V,0);
        queue<int> q;
        vector<int> sorted;
        
        // Build adjacency list from edge list
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
        }

       // Iterate over and deduce the indegree
       for(int u=0;u<V;u++)
       {
           for(auto &v:adj[u])
           indegree[v]++;
       }
       
       //add all the nodes with degree 0 as first 
       for(int i=0;i<V;i++)
       {
           if(indegree[i]==0)
           q.push(i);
       }
       
       //BFS visit each nodes decrement each degree and push in queue
       while(!q.empty())
       {
           int u=q.front();
           sorted.push_back(u); // as queue will have elements which are 0 degree now
           q.pop();
           for(auto& v:adj[u])
           {
               indegree[v]--;
               if(indegree[v]==0) 
               {
                   q.push(v);
               }
               
           }
       }
       
       
       // return topo sorted BFS
        return sorted;
    }
};
