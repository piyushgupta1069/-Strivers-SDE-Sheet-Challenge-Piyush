int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
    for(auto it:edges){
        dp[it[0]][it[1]]=it[2];
    }
    for(int i=1;i<=n;i++){
        dp[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][k]==1e9||dp[k][j]==1e9)continue;
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    return dp[src][dest]==1e9?1e9:dp[src][dest];
}
