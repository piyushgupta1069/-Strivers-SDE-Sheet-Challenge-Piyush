#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int>* temp1=head,*temp2=head;
    int len=0;
    while(temp1!=NULL){
        len++;
        temp1=temp1->next;
    }
    temp1=head;
    int t = len/2;
    LinkedListNode<int>* curr=head, *pre=NULL;
    while(t--)
    {
        LinkedListNode<int>* temp11 = curr->next;
        curr->next=pre;
        pre=curr;
        curr=temp11;
    }
    temp1=pre;
    if(len&1)temp2=curr->next;
    else{
        temp2=curr;
    }
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1->data!=temp2->data)return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;

}
