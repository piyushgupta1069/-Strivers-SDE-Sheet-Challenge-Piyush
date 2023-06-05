#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    vector<pair<double,pair<int,int>>>v;
    for(int i=0;i<n;i++){
        v.push_back({items[i].second/double(items[i].first),{items[i].first,items[i].second}});
    }
    sort(v.begin(),v.end());
    double res=0.0;
    for(int i=n-1;i>=0;i--)
    {
        if(v[i].second.first<=w){
            res+=v[i].second.second;
            w-=v[i].second.first;
        }else{
            res+=w*v[i].first;
            break;
        }
    }
    return res;
}
