#include <bits/stdc++.h> 
int dp[101];
int solve(int i, unordered_set<string>&m, string &target)
{
    if(i>=target.size())return 1;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    string temp;
    for(int j=i;j<target.size();j++){
        temp+=target[j];
        if(m.count(temp)){
            ans|=solve(j+1,m,target);
        }
    }
    return dp[i]=ans;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    unordered_set<string>m(arr.begin(),arr.end());
    memset(dp,-1,sizeof(dp));
    return solve(0,m,target);
    
}
