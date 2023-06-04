#define ll long long
#include<bits/stdc++.h>
ll help(ll *arr, ll left, ll mid, ll right)
{
    int j=mid+1,t=0;
    ll res=0;
    for(int i=left;i<=mid;i++)
    {
        res+=t;
        while(j<=right&&arr[j]<arr[i])
        {
            t++;
            j++;
            res++;
        }
    }
    sort(arr+left,arr+right+1);
    return res;
}
void merge(ll *arr, int n, ll left, ll right, ll &res)
{
    if(left>=right)return;
    int mid = (left+right)>>1;
    merge(arr,n,left,mid,res);
    merge(arr,n,mid+1,right,res);
    res+=help(arr,left,mid,right);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    ll left = 0, right=n-1,res=0;
    merge(arr,n,left,right,res);
    return res;
}
