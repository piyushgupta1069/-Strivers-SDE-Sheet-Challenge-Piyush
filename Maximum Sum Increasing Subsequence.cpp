#include <bits/stdc++.h> 
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
	int dp[n];
	memset(dp,0,sizeof(dp));
	dp[0]=rack[0];
	for(int i=1;i<n;i++){
		dp[i]=rack[i];
		for(int j=0;j<i;j++){
			if(rack[i]>rack[j]){
				dp[i]=max(dp[i],dp[j]+rack[i]);
			}
		}
	}
	return *max_element(dp,dp+n);
}
