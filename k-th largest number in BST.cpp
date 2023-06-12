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
int help(TreeNode<int>* root){
    if(root==0)return 0;
    int cnt=1;
    cnt+=help(root->left);
    cnt+=help(root->right);
    return cnt;
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int n = help(root);
    k=n-k+1;
    while(root)
    {
        if(root->left)
        {
            TreeNode<int>* temp = root->left;
            while(temp->right&&temp->right!=root){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right=root;
                root=root->left;
            }else{
                root=temp->right;
                temp->right=NULL;
                k--;
                if(k==0)return root->data;
                root=root->right;
            }
        }else{
            k--;
            if(k==0)return root->data;
            root=root->right;
        }
    }
    return -1;
}
