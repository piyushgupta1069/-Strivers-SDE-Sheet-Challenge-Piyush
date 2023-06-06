#include <bits/stdc++.h> 
void solve(int i, int sum, vector<int>&res, vector<int>&num)
{
    if(i==num.size()){
        res.push_back(sum);
        return;
    }
    solve(i+1,sum,res,num);
    solve(i+1,sum+num[i],res,num);
}
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int sum=0;
    vector<int>res;
    solve(0,sum,res,num);
    sort(res.begin(),res.end());
    return res;
}
