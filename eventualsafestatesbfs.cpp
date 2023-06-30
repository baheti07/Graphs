#include<bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
     
        int n=graph.size();
        vector<int>adjr[n];
        int indegree [n]= {0};
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adjr[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjr[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    int main()
    {
        vector<vector<int>>graph={{1}, {2}, {3}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10}, 
        {8},{9}};
        vector<int>ans=eventualSafeNodes(graph);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    }