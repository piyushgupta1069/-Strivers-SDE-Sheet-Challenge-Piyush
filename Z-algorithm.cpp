int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	string temp = p+"$"+s;

	int len = temp.size();
	vector<int> pi(len);
	pi[0] = 0;
	for (int i = 1; i < len; i++) {
		pi[i] = 0;
		int j = pi[i - 1]; /* trying length j + 1 */
		while (j > 0 && temp[j] != temp[i]) {
			j = pi[j - 1];
		}
		if (temp[j] == temp[i]) {
			pi[i] = j + 1;
		}
	}

	int res=0;
	for(int i=p.size()+1;i<len;i++)
	{
		if(pi[i]==p.size())res++;
	}
	return res;
}
