#include <bits/stdc++.h> 
class Stack {
	// Define the data members.

   public:
   queue<int>q;
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q.empty();
    }

    void push(int element) {
        // Implement the push() function.
        int sz = q.size();
        q.push(element);
        for(int i=0;i<sz;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(q.size()){
            int t = q.front();
            q.pop();
            return t;
            
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(q.size())return q.front();
        return -1;
    }
};
