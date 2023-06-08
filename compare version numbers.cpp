#include <bits/stdc++.h> 
void help(string &s, vector<string>&v1)
{
    for(int i=0;i<s.size();)
    {
        if(s[i]=='.'){
            i++;
        }else{
            string temp;
            while(i<s.size()&&s[i]!='.'){
                if(s[i]=='0'&&temp.size()==0){
                    i++;
                    continue;
                }else{
                    temp+=s[i];
                }
                i++;
            }
            if(temp.size()==0)temp+='0';
            v1.push_back(temp);
        }
    }
}
int compareVersions(string a, string b) 
{
    // Write your code here
    vector<string>v1,v2;
    help(a,v1);
    help(b,v2);
    // for(auto it:v1){
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it:v2){
    //     cout<<it<<" ";
    // }
    while(v1.size()<v2.size())v1.push_back("0");
    while(v2.size()<v1.size())v2.push_back("0");
    for(int i=0;i<v1.size();i++){
        if(v1[i].size()==v2[i].size()){
            if(v1[i]<v2[i])return -1;
            if(v1[i]>v2[i])return 1;
        }else{
            if(v1[i].size()>v2[i].size())return 1;
            else return -1;
        }
    }
    return 0;
}
