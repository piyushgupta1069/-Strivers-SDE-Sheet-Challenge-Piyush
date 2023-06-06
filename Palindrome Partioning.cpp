#include <bits/stdc++.h> 
bool isPalindrome(string &s)
{
    int i = 0, j = s.size()-1;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
void solve(int i, vector<string>&temp, vector<vector<string>>&res, string &s)
{
    if(i>=s.size()){
        res.push_back(temp);
        return;
    }
    string tempstring;
    for(int k=i;k<s.size();k++){
        tempstring+=s[k];
        if(isPalindrome(tempstring)){
            temp.push_back(tempstring);
            solve(k+1,temp,res,s);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>>res;
    vector<string>temp;
    solve(0,temp,res,s);
    return res;
}
