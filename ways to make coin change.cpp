#include "bits/stdc++.h"
long dp[11][2002];
long solve(int i, int sum, int n, int value, int *denominations)
{
    if(sum==value)return 1;
    if(i>=n)return 0;
    
    if(dp[i][sum]!=-1)return dp[i][sum];
    long ans = 0;
    if(sum+denominations[i]<=value)ans+=solve(i,sum+denominations[i],n,value,denominations);
    ans+=solve(i+1,sum,n,value,denominations);
    return dp[i][sum]=ans;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    memset(dp,-1,sizeof(dp));
    return solve(0,0,n,value,denominations);
}
