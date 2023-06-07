int kthElement(vector<int>& arr1, vector<int>& arr2, int n, int m, int k)
{
	if(n<m)return kthElement(arr2,arr1,m,n,k);
	
	int l=0,r=n;
	while(l<=r)
	{
		int cut1 = (l+r)>>1;
		int cut2 = k-cut1;
        if(cut2>m){
            l=cut1+1;
            continue;
        }
        if(cut2<0){
            r=cut1-1;
            continue;
        }
		int l1 = cut1==0?-1e9:arr1[cut1-1];
		int l2 = cut2==0?-1e9:arr2[cut2-1];
		int r1 = cut1==n?1e9:arr1[cut1];
		int r2 = cut2==m?1e9:arr2[cut2];
		if(l1<=r2&&l2<=r1){
			return max(l1,l2);
		}
		if(l1>r2)r=cut1-1;
		else l=cut1+1;
	}
	return 1;
}
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    // Write your code here.
    n=row1.size();
    m=row2.size();
    return kthElement(row1,row2,n,m,k);
}
