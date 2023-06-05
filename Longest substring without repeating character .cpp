#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    map<char,int>m;
    int n = input.size();
    int res=0,j=0;
    for(int i=0;i<n;i++){
        m[input[i]]++;
        if(m[input[i]]>1){
            while(j<i&&m[input[i]]>1){
                m[input[j]]--;
                j++;
            }
        }
        res=max(res,i-j+1);
    }
    return res;
}
