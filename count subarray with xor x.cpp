#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    map<int,int>m;
    int n = arr.size();
    int xorr=0;
    m[0]++;
    int res=0;
    for(int i=0;i<n;i++){
        xorr^=arr[i];
        res+=m[(xorr^x)];
        m[xorr]++;
    }
    return res;
}
