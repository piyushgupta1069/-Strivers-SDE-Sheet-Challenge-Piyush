#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.\
    // ceil
    int res=1e9;
    pair<int,int>ans={-1,-1};
    BinaryTreeNode<int>* temp=root;
    while(temp){
        if(temp->data>key){
            if(temp->data<res){
                res=temp->data;
                ans.second=temp->data;
            }
            temp=temp->left;
        }else temp=temp->right;
    }
    // floor
    res=-1e9;
    while(root){
        if(root->data<key){
            if(root->data>res){
                res=root->data;
                ans.first=root->data;
            }
            root=root->right;
        }else root=root->left;
    }
    return ans;
}
