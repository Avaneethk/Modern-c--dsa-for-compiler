class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec : edges){
            int u=vec[0];
            int v=vec[1];
            int w=vec[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        //You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> result(n+1,INT_MAX);
        vector<int> parent(n+1);
        
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        
        result[1]=0;
        pq.push({0,1}); //{node,distance}
        
        while(!pq.empty())
        {
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto &it: adj[node])
            {
                int adjNode = it.first;
                int dist = it.second;
                
                if(d+dist<result[adjNode])
                {
                    result[adjNode]=d+dist;
                    pq.push({d+dist,adjNode});
                    parent[adjNode]=node;
                }
            }
        }
        
        
        int destNode = n;
        if(result[destNode]==INT_MAX)
            return{-1};
        vector<int> path;    
        while(parent[destNode] != destNode)
        {
            path.push_back(destNode);
            destNode=parent[destNode];
        }
        path.push_back(1);
        reverse(begin(path),end(path));
        path.insert(path.begin(), result[n]);

        
        return path;
        

    }
};
