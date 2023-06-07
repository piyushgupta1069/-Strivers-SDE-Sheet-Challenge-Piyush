#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int n,arr[1005],ind1,ind2;
    Stack(int capacity) {
        // Write your code here.
        n=capacity;
        ind1=0;
    }

    void push(int num) {
        // Write your code here.
        if(ind1!=n){
            arr[ind1++]=num;
        }
        
    }

    int pop() {
        // Write your code here.
        if(ind1==0)return -1;
        ind1--;
        return arr[ind1];
    }
    
    int top() {
        // Write your code here.
        if(ind1==0)return -1;
        return arr[ind1-1];
    }
    
    int isEmpty() {
        // Write your code here.
        return ind1==0;
    }
    
    int isFull() {
        // Write your code here.
        return ind1==n;
    }
    
};
