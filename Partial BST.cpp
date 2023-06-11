#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool solve(int l, int r, BinaryTreeNode<int>* root)
{
    if(root==NULL)return true;
    if(root->data<l||root->data>r)return false;
    return solve(l,root->data,root->left)&&solve(root->data,r,root->right);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return solve(-1e9,1e9,root);
}
