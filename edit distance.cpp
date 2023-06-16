#include "bits/stdc++.h"
int dp[1001][1001];
int solve(int i, int j, string &str1, string &str2)
{
    if(i>=str1.size())return str2.size()-j;
    if(j>=str2.size())return str1.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans = 1e9;
    if(str1[i]==str2[j])ans = min(ans, solve(i+1,j+1,str1,str2));
    else{
        ans = min(ans, 1+solve(i,j+1,str1,str2));
        ans = min(ans, 1+solve(i+1,j+1,str1,str2));
        ans = min(ans, 1+solve(i+1,j,str1,str2));
    }
    return dp[i][j]=ans;
}
int editDistance(string str1, string str2)
{
    //write you code here
    memset(dp,-1,sizeof(dp));
    return solve(0,0,str1,str2);
}
