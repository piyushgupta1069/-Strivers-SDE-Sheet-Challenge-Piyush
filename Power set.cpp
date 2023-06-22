#include <bits/stdc++.h> 
void solve(int i, vector<int>&v, vector<vector<int>>&res, vector<int>temp)
{
    if(i>=v.size()){
        res.push_back(temp);
        return;
    }
    temp.push_back(v[i]);
    solve(i+1,v,res,temp);
    temp.pop_back();
    solve(i+1,v,res,temp);
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>>res;
    vector<int>temp;
    solve(0,v,res,temp);
    return res;
}
