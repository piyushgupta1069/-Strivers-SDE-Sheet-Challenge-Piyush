#include <bits/stdc++.h> 
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTiterator
{
    public:
    stack<BinaryTreeNode<int>*>s;
    bool reverse;
    void pushAll(BinaryTreeNode<int>*root){
        while(root){
            s.push(root);
            if(!reverse)root=root->left;
            else root=root->right;
        }
    }
    BSTiterator(BinaryTreeNode<int> *root, bool reverse)
    {
        // write your code here
        this->reverse=reverse;
        pushAll(root);

    }

    int next()
    {
        // write your code here
        auto node = s.top();
        s.pop();
        if(!reverse)pushAll(node->right);
        else pushAll(node->left);
        return node->data;
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator l = BSTiterator(root,false);
    BSTiterator r = BSTiterator(root,true);
    int i = l.next(), j = r.next();
    while(i<j){
        int sum = i+j;
        if(sum<k)i=l.next();
        else if(sum>k)j=r.next();
        else return true;
    }
    return false;
}
