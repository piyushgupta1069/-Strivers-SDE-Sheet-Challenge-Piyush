#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(m.count(arr[i]-1))continue;
        int tempres=1,tempNum=arr[i]+1;
        while(m.count(tempNum)){
            tempres++;
            tempNum+=1;
        }
        res=max(res,tempres);
    }
    return res;
}
