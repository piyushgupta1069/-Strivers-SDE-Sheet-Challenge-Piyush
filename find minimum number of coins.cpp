#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    int res=0;
    vector<int>v={1000,500,100,50,20,10,5,2,1};
    for(int i=0;i<v.size();i++){
        if(v[i]<=amount){
            int t = amount/v[i];
            res+=t;
            amount-=(t*v[i]);
            
        }
    }
    return res;
}
