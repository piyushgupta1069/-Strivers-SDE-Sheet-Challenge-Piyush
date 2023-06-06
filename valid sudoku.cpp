bool valid(int i, int j, int c, int matrix[9][9])
{
    int row = i-i%3, col = j-j%3;
    for(int k=0;k<9;k++)
    {
        if(matrix[i][k]==c)return false;
        if(matrix[k][j]==c)return false;
    }
    for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(matrix[row+x][col+y] == c) return false;

    
    return true;

}
bool solve(int row, int col, int matrix[9][9])
{
    if(row==9)return true;
    if(col==9)return solve(row+1,0,matrix);
    if(matrix[row][col]!=0)return solve(row,col+1,matrix);
    for(int i=1;i<=9;i++){
        if(valid(row,col,i,matrix)){
            matrix[row][col]=i;
            if(solve(row,col+1,matrix))return true;
            matrix[row][col]=0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return solve(0,0,matrix);
}
