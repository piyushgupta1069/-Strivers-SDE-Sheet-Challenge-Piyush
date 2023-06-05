int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	
	int ans=0;
	for(int i=0;i<n;)
	{
		int t=arr[i];
		while(i<n&&t==arr[i]){
			i++;
		}
		ans++;
	}
	return ans;
}
