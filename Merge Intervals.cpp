#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(),intervals.end());
    int n = intervals.size();
    vector<vector<int>>res;
    int l=-1,r=-1;
    for(int i=0;i<n;i++){
        if(l==-1){
            l=intervals[i][0];
            r=intervals[i][1];
        }else{
            if(intervals[i][0]>r){
                res.push_back({l,r});
                l=intervals[i][0];
                r=intervals[i][1];
            }else{
                r=max(r,intervals[i][1]);
            }
        }
    }
    if(l!=-1)res.push_back({l,r});
    return res;
}
