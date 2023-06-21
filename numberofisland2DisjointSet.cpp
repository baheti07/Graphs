#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
    vector<int>  parent, size;
public:
  
    DisjointSet(int n) {
         
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
 bool isvalid(int adjr,int adjc,int n,int m);
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col]=1;
            cnt++;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int ind=0;ind<4;ind++)
            {
                int adjr=row+dr[ind];
                int adjc=col+dc[ind];
                if(isvalid(adjr,adjc,n,m))
                {
                    if(vis[adjr][adjc]==1)
                    {
                        int nodeno=row*m+col;
                        int adjnodeno=adjr*m+adjc;
                        if(ds.findUPar(nodeno)!=ds.findUPar(adjnodeno))
                        {
                            cnt--;
                            ds.unionBySize(nodeno,adjnodeno);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
    bool isvalid(int adjr,int adjc,int n,int m)
    {
        return adjr>=0 && adjr<n &&adjc>=0 && adjc<m;
    }
    int main()
    {
        int n=4;
        int m=5;
        int k=4;
        vector<vector<int>>operators={{1,1},{0,1},{3,3},{3,4}};
        vector<int>ans=numOfIslands(n,m,operators);
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }