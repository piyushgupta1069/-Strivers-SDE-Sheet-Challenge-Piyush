#include <bits/stdc++.h> 
class DSU{
	public:
	vector<int>sz,par;
	DSU(int n){
		sz.resize(n+1);
		par.resize(n+1);
		for(int i=1;i<=n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}
	int findPar(int node)
	{
		if(par[node]==node)return node;
		return par[node]=findPar(par[node]);
	}
	void Union(int x, int y)
	{
		int repx = findPar(x);
		int repy = findPar(y);
		if(repx==repy)return;
		if(sz[repx]<sz[repy])swap(repx,repy);
		par[repy]=repx;
		sz[repx]+=sz[repy];
	}
};

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
	vector<array<int,3>>v;
	for(auto it:graph)
	{
		v.push_back({it[2],it[0],it[1]});
	}
	sort(v.begin(),v.end());
	DSU dsu(n);
	int res=0;
	for(int i=0;i<v.size();i++){
		int x = v[i][1];
		int y = v[i][2];
		int w = v[i][0];
		if(dsu.findPar(x)==dsu.findPar(y))continue;
		res+=w;
		dsu.Union(x,y);
	}
	return res;
}
