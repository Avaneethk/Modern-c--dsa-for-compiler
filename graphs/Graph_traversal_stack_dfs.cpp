#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void stack_dfs(int start,const vector<vector<int>>& adj)
{
    int n = adj.size();
    vector<bool> visited(n,false);
    stack<int> s;
    s.push(start);
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!visited[node])
        {
            visited[node]=true;
            cout<<node<<endl;
            for(auto it=adj[node].rbegin();it!=adj[node].rend();++it)
            {
                if(!visited[*it])
                s.push(*it);
            }
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
    //vector<bool> visited(nodes,false);
    //send start node adj matrix
    stack_dfs(0,adj);
    return 0;
}
