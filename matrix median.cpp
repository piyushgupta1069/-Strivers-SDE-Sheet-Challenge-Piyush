bool help(int mid, vector<vector<int>>&a)
{
    int t=0;
    int n = a.size(),m=a[0].size();
    for(int i=0;i<n;i++){
        t+=lower_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
    }
    return (t>=(n*m-t));
}
int getMedian(vector<vector<int>> &a)
{
    // Write your code here.
    int mn=1e9, mx=0;
    int n = a.size(), m = a[0].size();
    for(int i=0;i<n;i++)
    {
        mn=min(mn,a[i][0]);
        mx=max(mx,a[i][m-1]);
    }
    int l=mn,r=mx;
    while(l<=r){
        int mid = (l+r)>>1;
        if(help(mid,a)){
            r=mid-1;
        }else l=mid+1;
    }
    return r;
}
