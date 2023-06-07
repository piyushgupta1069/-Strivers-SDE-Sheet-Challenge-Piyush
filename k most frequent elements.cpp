#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    // Write your code here.
    unordered_map<int,int>m;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    for(auto it:m)
    {
        // cout<<it.first<<" "<<it.second<<endl;
        if(pq.size()<k){
            pq.push({-it.second,it.first});
        }else{
            if(-pq.top().first<it.second){
                pq.pop();
                pq.push({-it.second,it.first});
            }
        }
    }
    vector<int>res;
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(),res.end());
    return res;
}
