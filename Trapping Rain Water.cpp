#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long res=0,left=0,right=n-1;
    long mxleft=0,mxright=0;
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            mxleft=max(mxleft,arr[left]);
            res+=(mxleft-arr[left]);
            left++;
        }
        else{
            mxright=max(mxright,arr[right]);
            res+=(mxright-arr[right]);
            right--;
        }
    }
    return res;
}
