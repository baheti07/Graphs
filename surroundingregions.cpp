#include<bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& mat,
            int delrow[], int delcol[]){
        
        vis[row][col] = 1;
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i = 0; i < 4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if((nrow >= 0 && nrow < n) && (ncol >= 0 && ncol < m) &&
              mat[nrow][ncol]  && !vis[nrow][ncol] == 'O'){
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
            
        }
    }
    vector<vector<char>>fill(int n,int m, vector<vector<char>>& mat) {
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < m; i++){
            if(!vis[0][i]  && mat[0][i] == 'O'){
                dfs(0, i, vis, mat, delrow, delcol);
            }
            if(!vis[n-1][i]  && mat[n-1][i] == 'O'){
                dfs(n-1, i, vis, mat, delrow, delcol);
            }
        }
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i, 0, vis, mat, delrow, delcol);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i, m-1, vis, mat, delrow, delcol);
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j ++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
    int main()
    {
        vector<vector<char>>mat={{'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
                    };
                    int n=mat.size();
                    int m=mat[0].size();
                    vector<vector<char>>res=fill(n,m,mat);
                    for(int i=0;i<res.size();i++)
                    {
                        for(int j=0;j<res[i].size();j++) cout<<res[i][j]<<" ";
                        cout<<endl;
                    }


    }