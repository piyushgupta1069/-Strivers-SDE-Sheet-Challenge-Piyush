#include <bits/stdc++.h> 
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
	priority_queue<int>pq;
	for(int i=0;i<K;i++){
		pq.push(-arr[i]);
	}
	for(int i=K;i<size;i++){
		if(arr[i]>-pq.top()){
			pq.pop();
			pq.push(-arr[i]);
		}
	}
	return -pq.top();

}
