class Solution {
  public:
  
   bool checkBipartitieDFS(vector<vector<int>>&adj,int curr,vector<int>& color,int currcolor)
   {
      color[curr]=currcolor;
      for(int &v:adj[curr])
      {
          if(color[v]==color[curr])
          return false;
          
          if(color[v]==-1)//never colored
          {
              int colorofV = 1-currcolor;
              if(checkBipartitieDFS(adj,v,color,colorofV)==false)
              return false;
          }
      }
      return true;
   }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        
      vector<int> color(V,-1); //no node is coloured 
      vector<vector<int>>adj(V);
      
      //create adjacency matrix 
      for(auto &e:edges)
      {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
      }
      //consider red as 1 and green as 0
      for(int i=0;i<V;i++)
      {
          if(color[i]==-1)
          {
              if(checkBipartitieDFS(adj,i,color,1)==false) //assume curr color as red / first color
              return false;
          }
      }
      return true;
      
        
    }
};
