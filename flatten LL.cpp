/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */
Node* merge(Node* head1, Node* head2)
{
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    Node* dummy = new Node(-1), *temp=dummy;
    while(head1!=NULL&&head2!=NULL){
        if(head1->data<=head2->data){
            temp->child=head1;
            head1=head1->child;
        }else{
            temp->child=head2;
            head2=head2->child;
        }
        temp=temp->child;
    }
    if(head1!=NULL)temp->child=head1;
    if(head2!=NULL)temp->child=head2;
    return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{

	if(head==NULL)return NULL;
	Node* head1 = head;
	Node* head2 = flattenLinkedList(head->next);
	head->next=NULL;
   return head= merge(head1,head2);
}
