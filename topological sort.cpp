#include <bits/stdc++.h> 
void dfs(int node, vector<int>adj[], vector<int>&vis, stack<int>&s)
{
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])dfs(it,adj,vis,s);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>adj[v];
    vector<int>vis(v);
    for(auto it:edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int>res;
    stack<int>s;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,adj,vis,s);
        }
    }
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}
