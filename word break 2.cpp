#include <bits/stdc++.h> 

void solve(int i, vector<string>&temp, vector<string>&res, string &s, unordered_set<string>&m)
{
    if(i>=s.size()){
        string x;
        for(int k=0;k<temp.size();k++){
            x+=temp[k];
            if(k!=temp.size()-1)x+=' ';
        }
        res.push_back(x);
        return;
    }
    string t;
    for(int k=i;k<s.size();k++){
        t+=s[k];
        if(m.count(t)){
            temp.push_back(t);
            solve(k+1,temp,res,s,m);
            temp.pop_back();
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string>m(dictionary.begin(),dictionary.end());
    vector<string>res;
    vector<string>temp;
    solve(0,temp,res,s,m);
    return res;

}
