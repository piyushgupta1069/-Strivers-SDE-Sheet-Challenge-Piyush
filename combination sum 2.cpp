#include "bits/stdc++.h"
void solve(int i, vector<int>&temp, vector<vector<int>>&res, vector<int>&arr, int target)
{
	if(target==0)res.push_back(temp);
	for(int k=i;k<arr.size();k++){
		if(k>i&&arr[k]==arr[k-1])continue;
		temp.push_back(arr[k]);
		solve(k+1,temp,res,arr,target-arr[k]);
		temp.pop_back();
	}
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>res;
	vector<int>temp;
	solve(0,temp,res,arr,target);
	return res;
}
