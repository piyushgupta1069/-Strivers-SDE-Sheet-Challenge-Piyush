#include "bits/stdc++.h"
string reverseString(string &str){
	// Write your code here.
	string res;
	for(int i=str.size()-1;i>=0;){
		string temp;
		while(i>=0&&str[i]!=' '){
			temp.push_back(str[i]);
			i--;
		}
		reverse(temp.begin(),temp.end());
		if(temp.size())temp+=' ';
		while(i>=0&&str[i]==' ')i--;
		res+=temp;
	}	
	while(res.size()&&res.back()==' ')res.pop_back();
	return res;
}
