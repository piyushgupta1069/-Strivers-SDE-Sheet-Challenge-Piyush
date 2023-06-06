#include <bits/stdc++.h> 
void solve(int i, string &s, vector<string>&res)
{
    if(i>=s.size()){
        res.push_back(s);
        return;
    }
    for(int k=i;k<s.size();k++){
        swap(s[i],s[k]);
        solve(i+1,s,res);
        swap(s[i],s[k]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>res;
    solve(0,s,res);
    return res;
}
