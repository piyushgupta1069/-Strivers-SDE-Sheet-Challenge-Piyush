#include <bits/stdc++.h> 
int romanToInt(string s) {
    // Write your code here
    map<char,int>m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    int res=0;
    for(int i=0;i<s.size();)
    {
        if(i+1<s.size()&&m[s[i]]<m[s[i+1]]){
            res+=(m[s[i+1]]-m[s[i]]);
            i+=2;
        }else{
            res+=m[s[i]];
            i++;
        }
    }
    return res;
}
