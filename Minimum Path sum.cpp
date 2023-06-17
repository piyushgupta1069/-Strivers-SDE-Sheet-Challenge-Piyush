#include <bits/stdc++.h> 
int dp[101][101];
int solve(int i, int j, int n, int m, vector<vector<int>>&grid)
{
    if(i==n-1&&j==m-1)return grid[i][j];
    // if(i>=n&&j>=m)return 0;
    if(i>=n||j>=m)return 1e9;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = 1e9;
    
    ans = min(ans, grid[i][j]+min(solve(i+1,j,n,m,grid),solve(i,j+1,n,m,grid)));

    return dp[i][j]=ans;
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    return solve(0,0,grid.size(),grid[0].size(),grid);
}
