/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head==NULL||k==0)return head;
     int len=0;
     Node* temp=head;
     while(temp!=NULL)
     {
          if(temp->next==NULL)
          {
               len++;
               break;
          }
          temp=temp->next;
          len++;
     }
     k%=len;
     if(k==0)return head;
     if(len==1)return head;
     temp->next=head;

     int t = len-k;
     temp=head;
     Node* temp1=head;
     while(t--)
     {
          if(t>0)
          {
               temp=temp->next;
          }
          temp1=temp1->next;
     }
     temp->next=NULL;
     head=temp1;
     return head;
}
