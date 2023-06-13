#include "bits/stdc++.h"
int help(priority_queue<int>&mn, priority_queue<int>&mx) {
	if(mn.size()==mx.size()){
		int t1 = -mn.top(), t2 = mx.top();
		return (t1+t2)/2;
	}
	return (mx.size()>mn.size()?mx.top():-mn.top());
}
vector<int> findMedian(vector<int> &arr, int n){
	
	vector<int>res;
	// Write your code here 
	priority_queue<int>mn,mx;
	for(int i=0;i<n;i++){
		int num = arr[i];
		if(mn.size()==0){
            mn.push(-num);
			res.push_back(help(mn,mx));
			continue;
        }
        if(num>-mn.top()){
            mn.push(-num);
            if(mn.size()-mx.size()>1){
                mx.push(-mn.top());
                mn.pop();
            }
        }else{
            mx.push(num);
            if(mx.size()-mn.size()>1){
                mn.push(-mx.top());
                mx.pop();
            }
        }
		res.push_back(help(mn,mx));

	}
	return res;
}
