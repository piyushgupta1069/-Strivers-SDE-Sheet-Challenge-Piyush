#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int sum) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>res;
	for(int i=0;i<arr.size();i++)
	{
		if(i>0&&arr[i]==arr[i-1])continue;
		int j=i+1,k=arr.size()-1;
		while(j<k)
		{
			int tempSum = arr[j]+arr[k]+arr[i];
			if(tempSum<sum){
				j++;
			}
			else if(tempSum>sum){
				k--;
			}else{
				res.push_back({arr[i],arr[j],arr[k]});
				j++;
				k--;
				while(j<k&&arr[j]==arr[j-1]){
					j++;
				}
				while(j<k&&arr[k]==arr[k+1])k--;
				
			}
		}
	}
	
	return res;

}
