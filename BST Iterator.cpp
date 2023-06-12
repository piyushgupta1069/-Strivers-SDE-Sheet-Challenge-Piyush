#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    public:
    stack<TreeNode<int>*>s;
    void pushAll(TreeNode<int>*root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushAll(root);

    }

    int next()
    {
        // write your code here
        auto node = s.top();
        s.pop();
        pushAll(node->right);
        return node->data;
    }

    bool hasNext()
    {
        // write your code here
        return !s.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
