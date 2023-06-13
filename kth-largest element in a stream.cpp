#include <bits/stdc++.h> 
class Kthlargest {
public:
priority_queue<int>pq;
int k;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       this->k=k;
       for(int i=0;i<arr.size();i++){
           pq.push(-arr[i]);
       }
       while(pq.size()>k){
           pq.pop();
       }
    }

    void add(int num) {
        // Write your code here.
        pq.push(-num);
        while(pq.size()>k){
            pq.pop();
        }
    }

    int getKthLargest() {
       // Write your code here.
       return -pq.top();
    }

};
