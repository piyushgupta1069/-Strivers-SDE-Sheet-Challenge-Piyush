#include <bits/stdc++.h> 
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
	int l = 0, r = N-1;
	int target = levelOrder[N-1];
	vector<int>v(N,-1);
	bool found=false;
	for(int i=0;i<N;i++){
		if(inorder[i]==target)found=true;
		if(found)v[i]=1;
	}
	unordered_map<int,int>m;
	for(int i=0;i<N;i++){
		m[inorder[i]]=i;
	}
	int res=0;
	for(int i=0;i<N;i++){
		// cout<<l<<" "<<r<<endl;
		int j = m[levelOrder[i]];
		if(j>=l&&j<=r){
			res++;
			if(v[j]==1){
				r=j;
			}else l=j;
		}
	}
	return res-1;
}
