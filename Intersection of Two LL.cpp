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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node* res=NULL;
    Node* temp1 = firstHead, *temp2 = secondHead;
    while(temp1!=NULL&&temp2!=NULL)
    {
        if(temp1==temp2){
            res=temp1;
            break;
        }
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==NULL&&temp2==NULL)break;
        if(temp1==NULL)temp1=secondHead;
        if(temp2==NULL)temp2=firstHead;
    }
    return res;
}
