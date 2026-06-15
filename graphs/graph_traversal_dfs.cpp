#include<iostream>
#include<vector>
using namespace std;

void dfs(int start_node,vector<vector<int>>&adj,vector<bool>&visited)
{
    visited[start_node]=true;
    cout<<start_node<<" ";
    for(int neighbour:adj[start_node])
    {
        if(!visited[neighbour]){
            dfs(neighbour,adj,visited);
        }
    }
}

int main()
{
    int nodes=5;
    vector<vector<int>> adj(nodes);//initialized to 0
    adj[0]={1,2};
    adj[1]={0};
    adj[2]={3,4};
    adj[3]={2};
    adj[4]={2};
    vector<bool> visited(nodes,false);
    //send start node adj matrix
    dfs(0,adj,visited);
    return 0;
}
