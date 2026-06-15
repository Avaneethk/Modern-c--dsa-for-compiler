#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//pass the start node and adjacency list
void bfs(int start , const vector<vector<int>>& adj)
{
  int n = adj.size();
  vector<bool> visited(n,false);
  
  visited[start]=true;
  queue<int> q;
  q.push(start); //push 0
  while(!q.empty())
  {
      int node = q.front();
      q.pop();
      cout<<node<<endl;
      for(int neighbour:adj[node])
        if(!visited[neighbour])
        {
            visited[neighbour]=true;
            q.push(neighbour);
        }
  }
}


int main()
{
    //create adjacency list
    int nodes;
    cout<<"Enter the number of nodes"<<endl;
    cin>>nodes;
    vector<vector<int>>adj(nodes);
    //Tree
    //0:1,2
    //1:0,2,3
    //2:0,1,3
    //3:1,2
    adj[0].push_back(1);
    adj[0].push_back(2);
    
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    
    adj[3].push_back(1);
    adj[3].push_back(2);
    
    bfs(0,adj);
    
    return 0;
}
