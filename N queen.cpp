bool valid(int row, int col, vector<vector<int>>&v, int n)
{
    for(int i=0;i<n;i++)
    {
        if(v[row][i]==1||v[i][col]==1)return false;
    }
    int i=row, j = col;
    while(i>=0&&j>=0)
    {
        if(v[i][j]==1)return false;
        i--;
        j--;
    }
    i=row; j = col;
    while(i>=0&&j<n)
    {
        if(v[i][j]==1)return false;
        i--;
        j++;
    }
    i=row; j=col;
    while(i<n&&j>=0)
    {
        if(v[i][j]==1)return false;
        i++;
        j--;
    }
    i=row; j=col;
    while(i<n&&j<n)
    {
        if(v[i][j]==1)return false;
        i++;
        j++;
    }
    return true;

    
}
void solve(int row, vector<vector<int>>&temp, vector<vector<int>>&res, int n)
{
    if(row==n){
        vector<int>tempres;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tempres.push_back(temp[i][j]);
            }
        }
        res.push_back(tempres);
        return;
    }
    for(int col=0;col<n;col++){
        if(valid(row,col,temp,n)){
            temp[row][col]=1;
            solve(row+1,temp,res,n);
            temp[row][col]=0;
        }
    }
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>res;
    vector<vector<int>>temp(n,vector<int>(n,0));
    solve(0,temp,res,n);
    return res;
}
