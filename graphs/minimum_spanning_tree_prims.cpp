class Solution {
  typedef pair<int,int> P;
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        priority_queue<P,vector<P>,greater<P>> pq;
        
        //convert edge to adj list
        vector<vector<pair<int,int>>> adj(V);
        for(auto& e:edges){
        adj[e[0]].push_back({e[1],e[2]});
        adj[e[1]].push_back({e[0],e[2]});
        }       
        pq.push({0,0});
        vector<bool> inMST(V,false);
        int sum=0;
        
        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(inMST[node]==true)
            continue;
            
            inMST[node]=true;
            sum+=wt;
            
            for(auto& tmp:adj[node])
            {
                int neighbor = tmp.first;
                int neighbor_wt =tmp.second;
                
                if(inMST[neighbor]==false){
                    pq.push({neighbor_wt,neighbor});
                }
                
            }
        }
        
        return sum;
    }
};
