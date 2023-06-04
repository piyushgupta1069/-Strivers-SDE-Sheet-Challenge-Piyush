#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long>>res;
  res.push_back({1});
  if(n==1)return res;
  res.push_back({1,1});
  if(n==2)return res;
  for(int i=2;i<n;i++){
    vector<long long>v;
    v.push_back(1);
    for(int j=0;j<res[i-1].size();j++){
      if(j+1<res[i-1].size()){
        v.push_back(res[i-1][j]+res[i-1][j+1]);
      }else{
        v.push_back(1);
      }
    }
    res.push_back(v);
  }
  return res;
}
