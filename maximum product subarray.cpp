#include <bits/stdc++.h> 
int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
	int res=-1e9,sum=1;
	for(int i=0;i<n;i++){
		sum*=arr[i];
		res=max(res,sum);
		if(sum==0)sum=1;
	}
	sum=1;
	for(int i=n-1;i>=0;i--)
	{
		sum*=arr[i];
		res=max(res,sum);
		if(sum==0)sum=1;
	}
	return res;
}
