#include<bits/stdc++.h>
using namespace std;
void fnc(vector<vector<char>>&grid,int i,int j);
int island(vector<vector<char>>&grid)
{
    int r=grid.size();
    int c=grid[0].size();
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(grid[i][j]=='1')
            {
                fnc(grid,i,j);
                count++;
            }
        }
    }
    return count;
}
void fnc(vector<vector<char>>&grid,int i,int j)
{
    if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return;
    if(grid[i][j]=='0') return;
    grid[i][j]='0';
    fnc(grid,i,j-1);
    fnc(grid,i,j+1);
    fnc(grid,i-1,j);
    fnc(grid,i+1,j);
}
int main()
{
   vector<vector<char>> grid = {
       {'1', '1', '0', '0', '0'},
       {'1', '1', '0', '0', '0'},
       {'0', '0', '1', '0', '0'},
       {'0', '0', '0', '1', '1'}};
    cout<<island(grid);
}