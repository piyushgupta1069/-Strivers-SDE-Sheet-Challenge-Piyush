#include "bits/stdc++.h"
int minCharsforPalindrome(string s) {
	// Write your code here.
	string t;
	for(int i=0;i<s.size();i++)
	{
		t.push_back('#');
		t.push_back(s[i]);
	}
	t.push_back('#');
	int n = t.size();
	vector<int>p(n);
	int l=1,r=1;
	int ind=0,mx=0;
	
	for(int i=1;i<n;i++){
		p[i]=max(0,min(r-i,(l+r-i>=0?p[l+r-i]:0)));
		while((i-p[i])>=0&&(i+p[i])<n&&t[i-p[i]]==t[i+p[i]]){
			p[i]++;
		}
		
		if(i+p[i]>r){
			l=i-p[i];
			r=i+p[i];
		}
		if(l<1){
			ind=r;
		}
	}
	int res=0;
	for(int i=ind;i<n;i++){
		if(t[i]!='#')res++;
	}
	return res;
	
}
