bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n = mat.size(),m=mat[0].size();
    int l = 0, r = n*m-1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        int row = mid/m, col = mid%m;
        if(mat[row][col]==target)return true;
        if(mat[row][col]>target)r=mid-1;
        else l=mid+1;
    }
    return false;
}
