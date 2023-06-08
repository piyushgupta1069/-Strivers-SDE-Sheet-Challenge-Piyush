#include <bits/stdc++.h> 
bool findPattern(string p, string s)
{
    // Write your code here.
    string temp = p+"$"+s;

    int n = temp.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        pi[i] = 0;
        int j = pi[i - 1]; /* trying length j + 1 */
        while (j > 0 && temp[j] != temp[i]) {
            j = pi[j - 1];
        }
        if (temp[j] == temp[i]) {
            pi[i] = j + 1;
        }
    }

    
    for(int i=p.size()+1;i<n;i++)
    {
        if(pi[i]==p.size())return true;
    }
    return false;

}
