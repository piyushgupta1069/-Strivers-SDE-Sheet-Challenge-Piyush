int MOD = 1e6;
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    swap(str,pat);
    int t=1;
    int target=0;
    int m = str.size();
    for(int i=0;i<m;i++){
        t=(t*31)%MOD;
        target=(target*31+str[i])%MOD;
    }
    vector<int>res;
    int hash=0;
    
    for(int i=0;i<pat.size();i++)
    {
        hash = (hash*31+pat[i])%MOD;
        if(i<m-1)continue;
        if(i>=m)hash=(hash-pat[i-m]*t)%MOD;
        if(hash<0)hash+=MOD;
        if(hash==target){
            if(pat.substr(i-m+1,m)==str){
                res.push_back(i-m+1);
            }
        }
    }
    return res;
    
}
 
