int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
void dfs(int sr, int sc, int n, int m, vector<vector<int>>& image, int newColor, int color)
{
    if(sr<0||sc<0||sr>=n||sc>=m)return;
    if(image[sr][sc]!=color)return;
    image[sr][sc]=newColor;
    for(int i=0;i<4;i++){
        int x = sr+dx[i], y = sc+dy[i];
        dfs(x,y,n,m,image,newColor,color);
    }
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int n = image.size(), m = image[0].size();
    int color = image[sr][sc];
    if(color==newColor)return image;
    dfs(sr,sc,n,m,image,newColor,color);
    return image;
}
