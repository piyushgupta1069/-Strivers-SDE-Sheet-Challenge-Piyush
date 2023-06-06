#include <bits/stdc++.h> 
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool valid(int x, int y, int n){
    if(x<0||y<0||x>=n||y>=n)return false;
    return true;
}

void solve(int i, int j, int n, vector<vector<int>>&m, vector<vector<int>>&res, vector<int>&temp,vector<vector<int>>&vis)
{
    if(i==n-1&&j==n-1){
        // temp[i*n+j]=1;
        res.push_back(temp);
        return;
    }
    for(int k=0;k<4;k++){
        int xx = i+dx[k];
        int yy = j+dy[k];
        if(valid(xx,yy,n)&&m[xx][yy]==1&&!vis[xx][yy]&&temp[xx*n+yy]==0){
          temp[xx*n+yy]=1;
          vis[xx][yy]=1;
          solve(xx,yy,n,m,res,temp,vis);
          temp[xx*n+yy]=0;
          vis[xx][yy]=0;
        }
    }
    
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &m, int n){
  // Write your code here.
  vector<vector<int>>res;
  vector<int>temp(n*n,0);
  
  vector<vector<int>>vis(n,vector<int>(n,0));
  // vis[0][0]=1;
  if(m[0][0]==0)return res;
  temp[0]=1;
  solve(0,0,n,m,res,temp,vis);
  return res;
}
