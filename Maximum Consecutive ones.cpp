#include "bits/stdc++.h"
int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int j=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0){
            k--;
        }
        if(k<0){
            while(j<i){
                if(arr[j]==0){
                    j++;
                    k++;
                }
                else j++;
                if(k>=0)break;
            }
        }
        res=max(res,i-j+1);
    }
    return res;
} 
