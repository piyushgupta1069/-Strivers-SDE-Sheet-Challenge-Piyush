int dx[8]={-1,0,1,0,-1,-1,1,1};
int dy[8]={0,-1,0,1,-1,1,-1,1};
bool valid(int x, int y, int n, int m)
{
   if(x<0||y<0||x>=n||y>=m)return false;
   return true;
}
void dfs(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&vis, int n, int m)
{
   vis[i][j]=1;
   for(int k=0;k<8;k++)
   {
      int x = i+dx[k], y = j+dy[k];
      if(!valid(x,y,n,m))continue;
      if(vis[x][y]==1)continue;
      if(grid[x][y]==0)continue;
      dfs(x,y,grid,vis,n,m);
   }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
   int res=0;
   vector<vector<int>>vis(n,vector<int>(m,0));
   vector<vector<int>>grid(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         grid[i][j]=arr[i][j];
      }
   }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
            if(!vis[i][j]&&grid[i][j]==1){
               dfs(i,j,grid,vis,n,m);
               res++;
            }
      }
   }
   return res;
}
