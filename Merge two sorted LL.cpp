#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    Node<int>* dummy = new Node<int>(-1);
    Node<int>* tail=dummy;
    while(first&&second){
        if(first->data<second->data){
            tail->next=first;
            first=first->next;
        }else{
            tail->next=second;
            second=second->next;
        }
        tail=tail->next;
    }
    if(first){
        tail->next=first;
    }
    if(second){
        tail->next=second;
    }
    return dummy->next;
}
