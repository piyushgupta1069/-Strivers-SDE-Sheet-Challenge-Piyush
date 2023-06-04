#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	// using O(n) space
	// map<int,int>m;
	// for(int i=0;i<n;i++){
	// 	m[arr[i]]++;
	// 	if(m[arr[i]]>1)return arr[i];
	// }
	// return -1;
	
	// using constant space
	int i=0;
	while(true)
	{
		if(arr[i]!=arr[arr[i]])swap(arr[i],arr[arr[i]]);
		else{
			return arr[i];
		}
	}
	return -1;
}
