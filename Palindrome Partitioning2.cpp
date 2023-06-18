#include <bits/stdc++.h> 
int dp[101];
bool pal(string &s){
    int i=0,j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int solve(int i, string &str)
{
    if(i>=str.size())return 0;
    if(dp[i]!=-1)return dp[i];
    int ans=1e9;
    string temp;
    for(int j=i;j<str.size();j++){
        temp+=str[j];
        if(pal(temp)){
            ans = min(ans, 1+solve(j+1,str));
        }
    }
    return dp[i]=ans;
}
int palindromePartitioning(string str) {
    // Write your code here
    memset(dp,-1,sizeof(dp));
    return solve(0,str)-1;
}
