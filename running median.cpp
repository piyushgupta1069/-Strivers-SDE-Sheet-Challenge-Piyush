#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int>pq1,pq2;
    for(int i=0;i<n;i++){
        pq1.push(arr[i]);
        if(pq1.size()-pq2.size()>1){
            pq2.push(-pq1.top());
            pq1.pop();
        }
        if(pq1.size()&&pq2.size()&&pq1.top()>-pq2.top()){
            int t1 = pq1.top();pq1.pop();
            int t2 = -pq2.top();pq2.pop();
            pq1.push(t2);
            pq2.push(-t1);
        }
        if(pq1.size()==pq2.size()){
            cout<<(pq1.top()-pq2.top())/2<<" ";
        }else{
            cout<<(pq1.size()>pq2.size()?pq1.top():-pq2.top())<<" ";
        }
    }
}
