int singleNonDuplicate(vector<int>& nums)
{
	// Write your code here
	int n=nums.size(),l=0,r=n-1;
	if(n==1)return nums[0];
	while(l<=r){
		int mid = (l+r)>>1;
		if(mid-1<0||mid+1>=n){
			return nums[mid];
		}
		if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
			return nums[mid];
		}
		if(nums[mid]==nums[mid-1]){
			int right = r-mid+2;
			if(right%2)l=mid+1;
			else r=mid-2;
		}
		if(nums[mid]==nums[mid+1]){
			int left=mid-l+2;
			if(left%2)r=mid-1;
			else l=mid+2;
		}
	}
	return 0;
}
