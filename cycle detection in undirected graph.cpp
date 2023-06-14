#include <bits/stdc++.h> 
bool cycle(int node, int par, vector<int>adj[], vector<int>&vis)
{
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(cycle(it,node,adj,vis))return true;
        }else if(it!=par){
            return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int>vis(n+1);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(cycle(i,-1,adj,vis))return "Yes";
        }
    }
    return "No";
}
