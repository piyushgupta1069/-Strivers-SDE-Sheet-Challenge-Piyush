#include <bits/stdc++.h> 
string solve(string num, int cnt, int n)
{
	if(cnt>=n)return num;
	string temp;
	for(int i=0;i<num.size();)
	{
		char c = num[i];
		int cnt=0;
		while(i<num.size()&&num[i]==c){
			cnt++;
			i++;
		}
		temp+=to_string(cnt);
		temp+=c;
	}
	return (solve(temp,cnt+1,n));
}
string writeAsYouSpeak(int n) 
{
	// Write your code here.
	return solve("1",1,n);	
}
