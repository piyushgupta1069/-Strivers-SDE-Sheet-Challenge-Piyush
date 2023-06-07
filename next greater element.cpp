#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int>s;
    vector<int>res(n,-1);
    for(int i=0;i<n;i++){
        while(s.size()&&arr[s.top()]<arr[i]){
            res[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    return res;

}
