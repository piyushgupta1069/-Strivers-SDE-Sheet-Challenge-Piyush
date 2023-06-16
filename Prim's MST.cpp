#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>>adj[n+1];
    vector<int>vis(n+1);
    for(auto it:g){
        adj[it.first.first].push_back({it.first.second,it.second});
        adj[it.first.second].push_back({it.first.first,it.second});
    }
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({0,{1,-1}});
    int sum=0;
    vector<pair<pair<int,int>,int>>res;
    while(!pq.empty()){
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        int weight = -pq.top().first;
        pq.pop();
        if(vis[node]==1)continue;
        if(par!=-1)res.push_back({{node,par},weight});
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                pq.push({-it.second,{it.first,node}});
            }
        }
    }
    return res;

}
