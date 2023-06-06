#include <bits/stdc++.h> 
void solve(int i, vector<int>temp, vector<vector<int>>&res, vector<int>&arr)
{
    res.push_back(temp);
    for(int k=i;k<arr.size();k++){
        if(k>i&&arr[k]==arr[k-1])continue;
        temp.push_back(arr[k]);
        solve(k+1,temp,res,arr);
        temp.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>res;
    vector<int>temp;
    sort(arr.begin(),arr.end());
    solve(0,temp,res,arr);
    return res;
}
