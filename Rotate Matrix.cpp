#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int up = 0, down = n-1, left = 0, right = m-1;
    while(up<down&&left<right){
        // topmost
        int r = up, c = left;
        for(int i=left;i<=right;i++){
            swap(mat[r][c],mat[up][i]);
        }
        up++;
        // rightmost
        for(int i=up;i<=down;i++){
            swap(mat[r][c],mat[i][right]);
        }
        right--;
        // downmost
        if(up<=down){
            for(int i=right;i>=left;i--){
                swap(mat[r][c],mat[down][i]);
            }
            down--;
        }
        // leftmost
        if(left<=right){
            for(int i=down;i>=up;i--){
                swap(mat[r][c],mat[i][left]);
            }
            left++;
        }
    }

}
