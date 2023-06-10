#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int solve(BinaryTreeNode<int>*root,int mx)
{
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL){
        root->data=mx;
        return mx;
    }
    int leftt = solve(root->left,mx);
    int rightt = solve(root->right,mx);
    root->data=leftt+rightt;
    return root->data;

}
int maxi(BinaryTreeNode < int > * root)
{
    if(root==NULL)return 0;
    int leftt = maxi(root->left);
    int rightt = maxi(root->right);
    return max({root->data,leftt,rightt});
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    int mx=maxi(root);
    // cout<<mx<<endl;
    solve(root,mx);
}  
