#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &vec, int n, int edges, int source) {
    // Write your code here.
    priority_queue<int>pq;
    vector<pair<int,int>>adj[n];
    for(auto it:vec){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int>dis(n,INT_MAX);
    dis[source]=0;
    pq.push(source);
    while(!pq.empty()){
        int node = pq.top();
        pq.pop();
        for(auto it:adj[node]){
            int nodeNow = it.first;
            int weightNow = it.second;
            if(dis[nodeNow]>dis[node]+weightNow){
                dis[nodeNow]=dis[node]+weightNow;
                pq.push(nodeNow);
            }
        }
    }
    
    return dis;


}
