#include "bits/stdc++.h"
bool bfs(int n, vector<int>adj[], vector<int>&color, vector<int>&vis)
{
	queue<int>q;
	q.push(n);
	vis[n]=1;
	color[n]=1;
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(auto it:adj[node])
		{
			if(!vis[it])
			{
				color[it]=1-color[node];
				q.push(it);
				vis[it]=1;
			}
			else{
				if(color[it]==color[node]){
					return false;
				}
			}
		}
	}
	return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int n = edges.size();
    vector<int>adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<edges[0].size();j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	vector<int>color(n,-1),vis(n);
	for(int i=0;i<n;i++){
		if(!vis[i]){
			color[i]=0;
			if(!bfs(i,adj,color,vis))return false;
		}
	}
	return true;
}
