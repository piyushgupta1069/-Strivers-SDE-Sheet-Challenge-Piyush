#include <bits/stdc++.h>

string fourSum(vector<int> nums, int target, int n) {
    // Write your code here.
    sort(nums.begin(),nums.end());
    
    // -2 -1 0 0 1 2
    for(int i=0;i<n-3;i++)
    {
        if(i>0&&nums[i]==nums[i-1])continue;
        for(int j=i+1;j<n-2;j++)
        {
            if(j>i+1&&nums[j]==nums[j-1])continue;
            int left = j+1, right = n-1;
            while(left<right)
            {
                long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];
                if(sum<target)left++;
                else if(sum>target)right--;
                else{
                    return "Yes";
                }
            }
        }
    }
    return "No";
        
}
