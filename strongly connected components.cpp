#include "bits/stdc++.h"
void dfs(int node, vector<int>adj[], vector<int>&vis, stack<int>&s, int flag, vector<int>&v)
{
    vis[node]=1;
    v.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it])dfs(it,adj,vis,s,flag,v);
    }
    if(flag)s.push(node);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    stack<int>s;
    vector<int>adj[n];
    for(auto it:edges){
        adj[it[0]].push_back(it[1]);
    }
    vector<int>vis(n);
    vector<int>v;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            v.clear();
            dfs(i,adj,vis,s,1,v);
        }
    }
    vector<int>adjrev[n];
    for(int i=0;i<n;i++){
        vis[i]=0;
        for(auto it:adj[i]){
            adjrev[it].push_back(i);
        }
    }
    vector<vector<int>>res;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        if(!vis[node]){
            v.clear();
            dfs(node,adjrev,vis,s,0,v);
            res.push_back(v);
        }
    }
    return res;

}
