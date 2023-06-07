#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &A, vector<int> &B, int n, int k){
	// Write your code here.
	sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    sort(B.begin(),B.end());
    reverse(B.begin(),B.end());
    vector<int>res;
    int i=0,j=0;
    set<pair<int,int>>s;
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({A[0]+B[0],{0,0}});
    s.insert({0,0});
    for(int i=0;i<k;i++)
    {
        int sum = pq.top().first;
        int l = pq.top().second.first;
        int r = pq.top().second.second;
        pq.pop();
        res.push_back(sum);
        if(l+1<n&&s.count({l+1,r})==0){
            pq.push({A[l+1]+B[r],{l+1,r}});
            s.insert({l+1,r});
        }
        if(r+1<n&&s.count({l,r+1})==0){
            pq.push({A[l]+B[r+1],{l,r+1}});
            s.insert({l,r+1});
        }
        
    }
    return res;
}
