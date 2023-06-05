#include <bits/stdc++.h> 
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    vector<pair<int,int>>v;
    for(int i=0;i<jobs.size();i++){
        v.push_back({jobs[i][0],jobs[i][1]});
    }
    int res=0;
    sort(v.begin(),v.end());
    priority_queue<int>pq;
    for(int i=jobs.size()-1;i>=0;i--){
        int deadline = (i>0?v[i].first-v[i-1].first:v[i].first);
        pq.push(v[i].second);
        while(deadline&&!pq.empty()){
            res+=pq.top();
            deadline--;
            pq.pop();
        }
    }
    return res;
}
