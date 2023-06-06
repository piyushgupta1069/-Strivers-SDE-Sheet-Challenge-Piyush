bool help(int mid, int n, int m)
{
  long long  mul=1;
  for(int i=1;i<=n;i++){
    mul*=mid;
    if(mul>m)return false;
  }
  return mul<=m;
}
int NthRoot(int n, int m) {
  // Write your code here.
  int l=1,r=m;
  while(l<=r)
  {
    int mid = (l+r)>>1;
    if(help(mid,n,m))l=mid+1;
    else r=mid-1;
  }
  // cout<<l-1<<endl;
  int ans=l-1;
  r=1;
  for(int i=1;i<=n;i++){
    r*=ans;
  }
  if(r==m)return ans;
  return -1;
}
