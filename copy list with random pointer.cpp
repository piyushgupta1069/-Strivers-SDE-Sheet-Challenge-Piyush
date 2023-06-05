#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int>* ans; bool flag = 1;
    while(head != NULL){
        LinkedListNode<int>* tmp = new LinkedListNode<int>(head -> data);
        if(flag) ans = tmp, flag = 0;
        tmp -> next = head -> next;
        tmp -> random = head -> random;
        head = head -> next;
        tmp = tmp -> next;

    }
    return ans;

}
