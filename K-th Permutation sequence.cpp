string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int>v;
    int fac = 1;
    for(int i=1;i<n;i++){
        fac*=i;
        v.push_back(i);
    }
    v.push_back(n);
    k--;
    string res;
    while(true)
    {
        res+=to_string(v[k/fac]);
        v.erase(v.begin()+k/fac);
        if(v.size()==0)break;
        k%=fac;
        fac/=v.size();
        

    }
    return res;
}
