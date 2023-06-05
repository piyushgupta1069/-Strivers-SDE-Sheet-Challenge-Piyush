int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        v.push_back({at[i],-1});
        v.push_back({dt[i],1});
    }
    sort(v.begin(),v.end());
    int res=0,sum=0;
    for(int i=0;i<v.size();i++){
        sum-=v[i].second;
        res=max(res,sum);
    }
    return res;
}
