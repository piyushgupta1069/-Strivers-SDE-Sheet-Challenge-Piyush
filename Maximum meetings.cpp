#include <bits/stdc++.h> 
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n = start.size();
    vector<pair<pair<int,int>,int>>v;
    for(int i=0;i<n;i++)
    {
        v.push_back({{end[i],i+1},start[i]});
    }
    sort(v.begin(),v.end());
    vector<int>res;
    int l = -1, r = -1, ind=-1;
    for(int i=0;i<n;i++){
        if(l==-1){
            l=v[i].second;
            r=v[i].first.first;
            ind=v[i].first.second;
        }
        if(v[i].second>r){
            res.push_back(ind);
            l=v[i].second;
            r=v[i].first.first;
            ind=v[i].first.second;
        }
    }
    if(l!=-1)res.push_back(ind);
    return res;
}
