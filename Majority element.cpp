#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	// using moore voting algo
	int cnt=0,num=arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]==num)cnt++;
		else cnt--;
		if(cnt<0){
			num=arr[i];
			cnt=1;
		}
	}
	// checking
	cnt=0;
	for(int i=0;i<n;i++){
		if(arr[i]==num)cnt++;
	}
	if(cnt>n/2)return num;
	return -1;
}
