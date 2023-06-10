#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
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
bool leaf(TreeNode<int>* root)
{
    if(root->left==NULL&&root->right==NULL)return true;
    return false;
}
void leftview(TreeNode<int>*root, vector<int>&res)
{

    TreeNode<int>*node = root;
    node=node->left;
    while(node){
        if(!leaf(node))
            res.push_back(node->data);
        if(node->left)node=node->left;
        else node=node->right;
    }
}
void bottomview(TreeNode<int>*root, vector<int>&res)
{
    if(root==NULL)return;
    if(leaf(root)){
        res.push_back(root->data);
        // return;
    }
    bottomview(root->left,res);
    bottomview(root->right,res);
}
void rightview(TreeNode<int>*root, vector<int>&res)
{
    vector<int>temp;
    TreeNode<int>*node = root;
    node=node->right;
    while(node){
        if(!leaf(node))
            temp.push_back(node->data);
        if(node->right)node=node->right;
        else node=node->left;
    }
    for(int i=temp.size()-1;i>=0;i--)res.push_back(temp[i]);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res;
    if(root==NULL)return res;
    if(!leaf(root))res.push_back(root->data);
    leftview(root,res);
    bottomview(root,res);
    rightview(root,res);
    return res;
}
