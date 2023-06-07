#include <bits/stdc++.h> 
vector<int> merge(vector<int>&v1, vector<int>&v)
{   
    vector<int>res;
    int i=0,j=0;
    while(i<v1.size()&&j<v.size()){
        if(v1[i]<v[j])res.push_back(v1[i++]);
        else res.push_back(v[j++]);
    }
    while(i<v1.size())res.push_back(v1[i++]);
    while(j<v.size())res.push_back(v[j++]);
    return res;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int>res;
    for(int i=0;i<k;i++){
        if(i==0){
            res=kArrays[i];
        }else{
            vector<int>v1=res;
            res=merge(v1,kArrays[i]);
        }
    }
    return res;
}
