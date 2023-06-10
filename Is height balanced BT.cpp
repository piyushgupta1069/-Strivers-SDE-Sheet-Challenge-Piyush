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
int solve(BinaryTreeNode<int>* root,bool &res)
{
    if(root==NULL)return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    if(abs(l-r)>1)res=false;
    return max(l,r)+1;
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool res=true;
    solve(root,res);
    return res;
}
