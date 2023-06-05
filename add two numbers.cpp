/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
void add(Node* &head, int sum, Node* &temp)
{
    if(head==NULL){
        Node* temp1=new Node(sum);
        head=temp=temp1;
        return;
    }
    Node* temp1=new Node(sum);
    temp->next=temp1;
    temp=temp1;
}
Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    int carry=0;
    Node* head=NULL, *temp;
    while(num1!=NULL&&num2!=NULL)
    {
        int val1 = num1->data, val2 = num2->data;
        int sum = val1+val2+carry;
        carry=0;
        if(sum/10){
            carry=sum/10;
            sum%=10;
        }
        add(head,sum,temp);
        num1=num1->next;
        num2=num2->next;
    }
    while(num1!=NULL)
    {
        int sum = num1->data+carry;
        carry=0;
        if(sum/10){
            carry=sum/10;
            sum%=10;
        }
        add(head,sum,temp);
        num1=num1->next;
    }
    while(num2!=NULL)
    {
        int sum = num2->data+carry;
        carry=0;
        if(sum/10){
            carry=sum/10;
            sum%=10;
        }
        add(head,sum,temp);
        num2=num2->next;
    }
    if(carry){
        add(head,carry,temp);
    }
    return head;
}
