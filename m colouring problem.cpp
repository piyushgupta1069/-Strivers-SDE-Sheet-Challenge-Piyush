#include <bits/stdc++.h> 
bool help(int node, vector<int>&mark, int n, int m, int i, vector<vector<int>> &mat)
{
    for(int k=0;k<n;k++)
    {
        if(mat[node][k]==0)continue;
        if(mark[k]==i)return false;
    }
    return true;
}
bool solve(int node, vector<int>&mark, int n, int m, vector<vector<int>> &mat)
{
    if(node==n)return true;
    for(int i=0;i<m;i++)
    {
        if(help(node,mark,n,m,i,mat)){
            mark[node]=i;
            if(solve(node+1,mark,n,m,mat))return true;
            mark[node]=-1;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>mark(n,-1);
    bool t = solve(0,mark,n,m,mat);
    if(t)return "YES";
    return "NO";
}
