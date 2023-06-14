void dfs(int node, vector<int>&vis, vector<int>adj[], vector<int>&v)
{
    v.push_back(node);
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it])dfs(it,vis,adj,v);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>>res;
    vector<int>adj[V];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int>vis(V);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int>v;
            dfs(i,vis,adj,v);
            res.push_back(v);
        }
    }
    return res;
}
