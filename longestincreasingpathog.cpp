class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       vector<vector<int>>dp(n,vector<int>(m,-1));
       int ans=0;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               ans=max(ans,1+help(i,j,matrix,dp,n,m));
           }
       }
       return ans;

    }
    int help(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp,int n,int m)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ta=0;
        for(int k=0;k<4;k++)
        {
            int di=i+dr[k];
            int dj=j+dc[k];
            if(di>=0&&dj>=0&&di<n&&dj<m&&matrix[di][dj]>matrix[i][j])
            {
                ta=max(ta,1+help(di,dj,matrix,dp,n,m));
            }
        }
        return dp[i][j]=ta;
        
    }
};