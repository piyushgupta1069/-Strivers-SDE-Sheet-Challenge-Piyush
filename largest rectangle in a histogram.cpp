#include "bits/stdc++.h"
int largestRectangle(vector < int > & heights) {
   // Write your code here.
   int n = heights.size();
    stack<pair<int,int>>s;
    int res=0;
    for(int i=0;i<=n;i++)
    {
        while(s.size()&&(i==n||s.top().first>heights[i])){
            pair<int,int>p=s.top();
            s.pop();
            int r = i;
            int l=-1;
            if(s.size())l=s.top().second;
            res=max(res,p.first*(r-l-1));     
        }
        if(i<n)s.push({heights[i],i});
    }
    return res;
 }
