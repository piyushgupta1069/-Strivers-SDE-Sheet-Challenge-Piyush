#include "bits/stdc++.h"
vector<int> nextSmallerElement(vector<int> &A, int n)
{
    // Write your code here.
    stack<int>s;
    vector<int>res(A.size(),-1);
    for(int i=n-1;i>=0;i--){
        while(s.size()&&s.top()>=A[i]){
            s.pop();
        }
        if(s.size())res[i]=s.top();
        s.push(A[i]);
    }
    return res;
}
