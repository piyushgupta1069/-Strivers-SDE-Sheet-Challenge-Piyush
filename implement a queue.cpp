#include <bits/stdc++.h> 
class Queue {
    int n,arr[10005],ind1,ind2;
public:
    Queue() {
        // Implement the Constructor
        ind1=-1;
        ind2=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return ind1==ind2;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[++ind2]=data;

    }

    int dequeue() {
        // Implement the dequeue() function
        if(ind1==ind2)return -1;
        return arr[++ind1];
    }

    int front() {
        // Implement the front() function
        if(ind1==ind2)return -1;
        return arr[ind1+1];
    }
};
