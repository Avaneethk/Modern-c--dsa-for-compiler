class Solution {
public:
    bool toposortcheck(vector<vector<int>>& adj,vector<int>& indegree,int numCourses)
    {
       queue<int> q;
       int count=0;
       //if indegree 0 push into queue
       
       for(int i=0;i<numCourses;i++)
       {
        if(indegree[i]==0)
        {
        q.push(i);
        count++;
        }
       }
       
       //bfs
       while(!q.empty())
       {
        int u = q.front();
        q.pop();
        for(auto& v:adj[u])
           {
               indegree[v]--;
               if(indegree[v]==0) 
               {
                   q.push(v);
                   count++;
               }
               
           }
       }

       if(count==numCourses)
       return true;
       else 
       return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites ) {

        //step-1 try using kahn's algorithm approach
        //step-2 convert vector array into adjacency list 
        //step-3 update indegree
        //step-4 traverse graph using BFS and check if you have cycle
        //check if you have visited all nodes if yes then it is not a cycle else cycle

        vector<int>indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);


        for(auto &e:prerequisites) 
        {
            int a = e[0];
            int b = e[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        
        return toposortcheck(adj,indegree,numCourses);
     
    }
};
