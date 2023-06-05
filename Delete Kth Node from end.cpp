/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int len=0;
    Node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    // cout<<len<<endl;
    if(len==1)return NULL;
    int goalNode = len-K;
    if(goalNode==0){
        head=head->next;
        return head;
    }
    temp=head;
    while(goalNode>1)
    {
        goalNode--;
        temp=temp->next;
    }
    Node* removingNode=temp->next;
    temp->next=removingNode->next;
    removingNode->next=NULL;
    return head;
}
