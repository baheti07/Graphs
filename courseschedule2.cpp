#include<bits/stdc++.h>
using namespace std;
vector<int>order(int n,vector<vector<int>>& prerequisites)
        {
            int count = 0;
           queue<int>q;
           vector<int>indegree(n,0);
           vector<vector<int>>adj(n,vector<int>());
           for(vector<int>v:prerequisites)
           {
               adj[v[1]].push_back(v[0]);
               indegree[v[0]]++;
           }
           
           vector<int>ans;
           vector<bool>visited(n,false);
           for(int i=0;i<indegree.size();i++)
           {
               if(indegree[i]==0)
               {
                   q.push(i);
                   ans.push_back(i);
                   visited[i]=true;
                   count++;
               }
           }
           
           //BFS 
           while(!q.empty())
           {
               int node = q.front();
               q.pop();
               //visit its neighbours
                     
                vector<int>neighbours = adj[node];
               
               for(int neighbour:neighbours)
               {
                   if(!visited[neighbour])
                   {
                       indegree[neighbour]--;
                       if(indegree[neighbour]==0)
                       {
                           q.push(neighbour);
                           ans.push_back(neighbour);
                           visited[neighbour]=true;
                           count++;
                           
                       }
                       
                       
                   }
                   
                   
                   
               }
           }
               
              if(count!=n) return {};
               return ans;
        }
        int main()
        {
            int n=2;
            vector<vector<int>>prerequisites={{1,0}};
            vector<int>ans=order(n,prerequisites);
            for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        }