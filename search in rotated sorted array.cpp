int search(int* nums, int n, int target) {
    // Write your code here.
    int l = 0, r = n-1;
    int pivot=-1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(nums[mid]>=nums[0])l=mid+1;
        else if(nums[mid]<=nums[n-1])r=mid-1;
    }
    pivot=max(0,l-1);
    // cout<<pivot<<endl;
    if(target>=nums[0]&&target<=nums[pivot]){
        int lb = lower_bound(nums,nums+pivot+1,target)-nums;
        if(lb==pivot+1||nums[lb]!=target)return -1;
        return lb;
    }else{
        int lb = lower_bound(nums+pivot+1,nums+n,target)-nums;
        if(lb==n||nums[lb]!=target)return -1;
        return lb;
    }
    return -1;
}
