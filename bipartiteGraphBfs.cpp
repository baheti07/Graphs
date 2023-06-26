#include <bits/stdc++.h>
using namespace std;

	bool check(int start,int n, vector<int>adj[],int color[]){
	    // Code here
	    queue<int>q;
	    q.push(start);
	  
	    color[start]=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(auto it:adj[node])
	        {
	            if(color[it]==-1)
	            {
	                color[it]=!color[node];
	                q.push(it);
	            }
	            else if(color[it]==color[node]) return false;
	        }
	    }
	    return true;
}
bool isBipartite(int V,vector<int>adj[])
{
    int color[V];
    for(int i=0;i<V;i++) color[i]=-1;
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(check(i,V,adj,color)==false) return false;
        }
    }
    return true;
}
void addedge(vector<int> adj[],int u,int v)
{
        adj[u].push_back(v); 
        adj[v].push_back(u);
}   
int main() {
	vector<int> adj[6];
    addedge(adj,0,1);
    addedge(adj,1,2);
    addedge(adj,1,4);
    addedge(adj,1,5);
    addedge(adj,2,3);
    addedge(adj,3,4);
    addedge(adj,3,5);

    if(checkBipartite(adj, 6)) {
        cout << "It is a Bipartite Graph"; 
    } else {
        cout << "It is not a Bipartite Graph"; 
    }
    return 0;
	
}