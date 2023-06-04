#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
	long double res=1;
	for(int i=1;i<=n+m-2;i++){
		res*=i;
	}
	for(int i=1;i<=n-1;i++){
		res/=i;
	}
	for(int i=1;i<=m-1;i++){
		res/=i;
	}
	return int(res);
}
