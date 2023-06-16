#include "bits/stdc++.h"
int dp[1001][1001];
int solve(int i, int sum, int w, vector<int>&values, vector<int>&weights)
{
	if(i>=values.size())return 0;
	if(dp[i][sum]!=-1)return dp[i][sum];
	int ans=0;
	ans=max(ans,solve(i+1,sum,w,values,weights));
	if(sum+weights[i]<=w){
		ans=max(ans,values[i]+solve(i+1,sum+weights[i],w,values,weights));
	}
	return dp[i][sum]=ans;
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
	memset(dp,-1,sizeof(dp));
	return solve(0,0,w,values,weights);
}
