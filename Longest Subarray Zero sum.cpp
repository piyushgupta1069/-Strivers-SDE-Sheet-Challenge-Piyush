#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector < int > A) {

  // Write your code here
  map<int,int>m;
  int sum=0;
  m[0]=-1;
  int res=0;
  for(int i=0;i<A.size();i++)
  {
      sum+=A[i];
      if(m.find(sum)!=m.end()){
        res=max(res,i-m[sum]);
      }
      else{
        m[sum]=i;
      }
  }
  
  return res;

}
