class Solution {
public:
int mod=1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        long count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                count=(count+dfs(i,j,grid,n,m,dp))%mod;
            }
        }
        return count;
    }
    int dfs(int i,int j, vector<vector<int>>&grid,int n,int m,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=1;
        for(int k=0;k<4;k++)
        {
            int di=i+dr[k];
            int dj=j+dc[k];
            if(di>=0&&dj>=0&&di<n&&dj<m&&grid[di][dj]>grid[i][j])
               ans=(ans+dfs(di,dj,grid,n,m,dp))%mod;
        }
        return dp[i][j]=ans;
    }
};