#include <bits/stdc++.h> 
int dp[1001][1001];
int solve(int i, int sum, vector<int>&arr)
{
    if(sum==0)return 1;
    if(i==0)return arr[i]==sum;
    
    if(dp[i][sum]!=-1)return dp[i][sum];
    int ans = 0;
    ans|=solve(i-1,sum,arr);
    if(arr[i]<=sum)ans|=solve(i-1,sum-arr[i],arr);
    return dp[i][sum]=ans;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    memset(dp,-1,sizeof(dp));
    int t= solve(n-1,k,arr);
    if(t)return true;
    return false;
}
