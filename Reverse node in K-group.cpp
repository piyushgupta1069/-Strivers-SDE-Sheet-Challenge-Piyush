#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
int findlen(Node* head)
{
	int len=0;
	while(head){
		len++;
		head=head->next;
	}
	return len;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
	int len = findlen(head);
	int ind=0;
	Node* dummy = new Node(-1),*temp=head,*tail=dummy;
	while(ind<n&&len>0)
	{
		int k = b[ind];
		Node* prev=NULL;
		while(temp!=NULL&&k>0){
			Node* temp1 = temp->next;
			temp->next=prev;
			prev=temp;
			temp=temp1;
			k--;
		}
		tail->next=prev;
		while(tail->next){
			tail=tail->next;
		}
		len-=b[ind];
		ind++;
		
	}
	if(len>0){
		tail->next=temp;
	}
	return dummy->next;
}
