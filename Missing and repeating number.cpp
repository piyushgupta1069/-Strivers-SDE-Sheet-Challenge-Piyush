#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int num=0;
	for(int i=0;i<n;i++){
		num^=(i+1);
		num^=arr[i];
	}
	int rightMostBit=0;
	int tempNum = num,ind=0;
	while(tempNum){
		if(tempNum%2)rightMostBit=ind;
		ind++;
		tempNum>>=1;
	}
	int x=0,y=0;
	for(int i=0;i<n;i++){
		int t = i+1;
		if(t&(1<<rightMostBit)){
			x^=t;
		}else{
			y^=t;
		}
		t = arr[i];
		if(t&(1<<rightMostBit)){
			x^=t;
		}else y^=t;
	}
	for(int i=0;i<n;i++){
		if(arr[i]==x){
			return {y,x};
		}
	}
	return {x,y};
	
}
