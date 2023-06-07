#include <bits/stdc++.h> 
vector<int>leftsmaller(vector<int>&a)
{
    stack<int>s;
    vector<int>res;
    for(int i=0;i<a.size();i++){
        while(!s.empty()&&a[s.top()]>=a[i]){
            s.pop();
        }
        if(s.size())res.push_back(s.top());
        else res.push_back(-1);
        s.push(i);
    }
    return res;
}
vector<int>rightsmaller(vector<int>&a)
{
    stack<int>s;
    vector<int>res;
    for(int i=a.size()-1;i>=0;i--){
        while(!s.empty()&&a[s.top()]>=a[i]){
            s.pop();
        }
        if(s.size())res.push_back(s.top());
        else res.push_back(a.size());
        s.push(i);
    }
    reverse(res.begin(),res.end());
    return res;
}
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int>res(n,-1e9);
    vector<int>left=leftsmaller(a);
    vector<int>right=rightsmaller(a);
    for(int i=0;i<n;i++){
        int ind = right[i]-left[i]-2;
        res[ind]=max(res[ind],a[i]);
    }
    for(int i=n-2;i>=0;i--){
        res[i]=max(res[i],res[i+1]);
    }
    return res;
    

}
