#include <bits/stdc++.h> 
bool help(long long mid, vector<int>&A, int B)
{
    int cnt=0;
    long long sum=0;
    for(int i=0;i<A.size();i++){
        if(sum+A[i]>mid){
            cnt++;
            sum=A[i];
            if(sum>mid)return false;
        }else{
            sum+=A[i];
        }
    }
    if(sum)cnt++;
    return cnt<=B;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here
    long long l=0,r=1e18;
    while(l<=r)
    {
        long long mid = (l+r)>>1;
        if(help(mid,time,n))r=mid-1;
        else l=mid+1;
    }
    return r+1;
}
