#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>v;
    for(int i=0;i<start.size();i++){
        v.push_back({finish[i],start[i]});
    }
    sort(v.begin(),v.end());
    int res=0,l = -1, r = -1;
    for(int i=0;i<v.size();i++){
        if(l==-1){
            l = v[i].second;
            r = v[i].first;
        }
        if(v[i].second>=r){
            res++;
            l = v[i].second;
            r = v[i].first;
        }
    }
    if(l!=-1)res++;
    return res;
}
