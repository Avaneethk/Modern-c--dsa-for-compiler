class Solution {
public:

/*   
void dfs(vector<vector<int>>& isConnected,int u,vector<bool>& visited)
    {
      visited[u]=true;
     for(int v = 0; v < isConnected[u].size(); ++v) 
      {
        if(isConnected[u][v] && !visited[v])
        {
            visited[v]=true;
            dfs(isConnected,v,visited);
        }
      }
    }
*/
void bfs(vector<vector<int>>& isConnected,int u,vector<bool>& visited)
{
   queue<int> q;
   q.push(u);
   visited[u]=true;


   while(!q.empty())
   {
    int curr = q.front();
    q.pop();

    for(v=0;v<isConnected[curr].size();v++)
    {
        if(isConnected[curr][v]==1 && !visited[v])
        {
        visited[v]=true;
        q.push(v);
        }
    }
    

   }
}
int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count=0;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
               bfs(isConnected,i,visited);
               count++;
               
            }
        }

        return count;
    }
};
