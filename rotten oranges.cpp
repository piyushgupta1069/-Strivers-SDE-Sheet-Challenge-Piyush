#include "bits/stdc++.h"
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int help(int x, int y, int n, int m)
{
    if(x<0||y<0||x>=n||y>=m)return false;
    return true;
}
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
                grid[i][j]=0;
            }
        }
    }
    /*
    2 2
    1 1
    0 0
    2 0
    */
    int res=0;
    while(!q.empty()){
        int sz = q.size();
        // cout<<sz<<endl;
        bool convert=false;
        for(int i=0;i<sz;i++){
            pair<int,int>p=q.front();
            // cout<<p.first<<" "<<p.second<<endl;
            q.pop();
            for(int k=0;k<4;k++){
                int x = p.first+dx[k];
                int y = p.second+dy[k];
                if(help(x,y,n,m)&&grid[x][y]==1){
                    convert=true;
                    // cout<<"enter->"<<" "<<x<<" "<<y<<endl;
                    q.push({x,y});
                    grid[x][y]=0;
                }
            }
        }
        if(convert)res++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1)res=-1;
        }
    }
    return res;  
}
