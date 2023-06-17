#include "bits/stdc++.h"
int dp[101];
int solve(int i, vector<int>&price)
{
	if(i>=price.size())return 0;
	if(dp[i]!=-1)return dp[i];
	int ans = 0;
	for(int k=i;k<price.size();k++){
		ans = max(ans, price[k-i]+solve(k+1,price));
	} 
	return dp[i]=ans;
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	memset(dp,-1,sizeof(dp));
	return solve(0,price);
}
