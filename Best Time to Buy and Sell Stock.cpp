#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn=1e9,mx=-1e9;
    int res=0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]<mn){
            mn=min(mn,prices[i]);
            mx=prices[i];
        }
        mx=max(mx,prices[i]);
        res=max(res,mx-mn);
    }
    return res;
}
