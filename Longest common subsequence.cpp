int dp[1001][1001];
int solve(int i, int j, string &s, string &t)
{
	if(i>=s.size()||j>=t.size())return 0;
	if(dp[i][j]!=-1)return dp[i][j];
	int ans=0;
	if(s[i]==t[j])ans = max(ans, 1+solve(i+1,j+1,s,t));
	else{
		ans = max(ans, max(solve(i+1,j,s,t),solve(i,j+1,s,t)));
	}
	return dp[i][j]=ans;
}
int lcs(string s, string t)
{
	//Write your code here
	memset(dp,-1,sizeof(dp));
	return solve(0,0,s,t);
}
