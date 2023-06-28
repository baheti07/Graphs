class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        //make the adjacency list from vector of vector
         vector<int>adj[n];
        for(auto it:prerequisites) adj[it[1]].push_back(it[0]);
        
	    vector<int>topo;
	    //vector<int>vis(n,0);
	    queue<int>q;
	    vector<int>indegree(n,0);
	    for(int i=0;i<n;i++)
	    {
	        for(auto it:adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(indegree[i]==0)
	        q.push(i);
	        
	    }
	    
	    while(!q.empty())
	    {
	        
	        int node=q.front();
	        q.pop();
			topo.push_back(node);
	        for(auto it:adj[node])
	        {
	                indegree[it]--;
	                if(indegree[it]==0)
	                q.push(it);
	        }
	    }
	    if(topo.size()==n) return true;
	    return false;
	    
    }
};