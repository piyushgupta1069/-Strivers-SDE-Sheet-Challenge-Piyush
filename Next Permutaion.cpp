#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    //  Write your code here.
    int ind = -1;
    for(int i=0;i<n-1;i++){
        if(p[i]<p[i+1]){
            ind=i;
        }
    }
    if(ind==-1){
        reverse(p.begin(),p.end());
        return p;
    }
    for(int i=n-1;i>ind;i--){
        if(p[i]>p[ind]){
            swap(p[i],p[ind]);
            break;
        }
    }
    reverse(p.begin()+ind+1,p.end());
    return p;
}
