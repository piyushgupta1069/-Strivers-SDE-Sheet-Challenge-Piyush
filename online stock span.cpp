#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>>s;
    vector<int>ans;
    for(int i=0;i<price.size();i++){
        int res=1;
        int p = price[i];
        while(s.size()&&s.top().first<=p){
            res+=s.top().second;
            s.pop();
        }
        s.push({p,res});
        ans.push_back(res);
    }
    return ans;
}
