#include "bits/stdc++.h"
class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int>in,out;
    Queue() {
        
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        in.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(out.empty()){
            while(in.size()){
                out.push(in.top());
                in.pop();
            }
        }if(out.size()==0)return -1;
        int t = out.top();
        out.pop();
        return t;
    }

    int peek() {
        // Implement the peek() function here.
        if(out.empty()){
            while(in.size()){
                out.push(in.top());
                in.pop();
            }
        }
        if(out.size()==0)return -1;
        return out.top();
    }

    bool isEmpty() {
        return (in.empty()&&out.empty());
        // Implement the isEmpty() function here.
    }
};
