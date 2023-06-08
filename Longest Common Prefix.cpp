string longestCommonPrefix(vector<string> &s, int n)
{
    // Write your code here
    string x = s[0];
    string temp;
    for(int i=1;i<n;i++)
    {
        int t=0;
        // cout<<s[i].size()<<endl;
        for(int j=0;j<s[i].size()&&t<x.size();j++)
        {
            // debug(t)
            if(x[t]==s[i][j])t++;
            else break;
        }
        t--;
        // debug(t)
        temp.clear();
        for(int j=0;j<=t;j++)
        {
            temp.push_back(x[j]);
        }
        x=temp;
        // debug(x)
    }
    return x;
}


