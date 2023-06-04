#include <bits/stdc++.h> 
void help(vector<int>&nums, int left, int mid, int right, int &res)
{
	int j=mid+1;
	vector<long long>v;
	for(int i=mid+1;i<=right;i++)
	{
		long long t = 2LL*nums[i];
		v.push_back(t);
	}
	for(int i=left;i<=mid;i++)
	{
		int lb = lower_bound(v.begin(), v.end(), nums[i])-v.begin();
		res+=lb;
	}
	sort(nums.begin()+left,nums.begin()+right+1);
	
}
void mergesort(vector<int>&nums, int left, int right, int &res)
{
	if(left>=right)return;
	int mid = (left+right)>>1;

	mergesort(nums,left,mid,res);
	mergesort(nums,mid+1,right,res);
	help(nums,left,mid,right,res);
}
int reversePairs(vector<int> &nums, int n){
	// Write your code here.
	int left = 0, right = nums.size()-1;
	int res=0;
	mergesort(nums,left,right,res);
	return res;	
}
