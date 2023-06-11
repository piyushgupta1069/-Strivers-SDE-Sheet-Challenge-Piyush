#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    TreeNode<int>* node = root;
    while(node)
    {
        if((node->data>=p->data&&node->data<=q->data)||(node->data>=q->data&&node->data<=p->data))
        {
            return node;
        }
        if(node->data>=p->data)node=node->left;
        else node=node->right;
    }
    return node;
}
