#include "bits/stdc++.h"
string longestPalinSubstring(string s)
{
    // Write your code here.
    // making an another string of odd length
    string t;
    for(int i=0;i<s.size();i++)
    {
        t.push_back('#');
        t.push_back(s[i]);
    }
    t.push_back('#');
    // cout<<t<<endl;
    int n = t.size();
    
    vector<int>p(n);// p[i]=longest palindromic having centre at i
    //  s-> a b a b a
    //  t->  # a # b # a # b # a #
    // p[i]= 1 2 1 4 1 6 1 4 1 2 1
    int l=1,r=1;
    p[0]=1;
    for(int i=1;i<n;i++){
        p[i]=max(0,min(r-i,(l+r-i>=0?p[l+r-i]:0)));
        while((i-p[i])>=0&&(i+p[i])<n&&t[i-p[i]]==t[i+p[i]]){
            p[i]++;
        }
        if(i+p[i]>r){
            l=i-p[i];
            r=i+p[i];
        }
    }

    int mx = *max_element(p.begin(),p.end());
    int ind=0;
    for(int i=0;i<n;i++){
        if(p[i]==mx){
            ind=i;
            break;
        }
    }
    string res;
    for(int i=ind-p[ind]+1;i<ind+p[ind];i++){
        if(t[i]!='#')res.push_back(t[i]);
    }
    return res;
}
