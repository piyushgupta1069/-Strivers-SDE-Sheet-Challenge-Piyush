#include <bits/stdc++.h> 
int dp[101][101];
int solve(int i, int j, vector<int>&arr)
{
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = 1e9;
    for(int k=i;k<=j-1;k++){
        ans = min(ans, arr[i-1]*arr[k]*arr[j]+solve(i,k,arr)+solve(k+1,j,arr));
    }
    return dp[i][j]=ans;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    return solve(1,N-1,arr);
}
