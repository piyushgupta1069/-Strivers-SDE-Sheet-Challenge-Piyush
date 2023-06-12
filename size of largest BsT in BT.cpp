#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data  = data;
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
class node{
    public:
    int mn,mx,sz;
    node(int mn, int mx, int sz){
        this->mn=mn;
        this->mx=mx;
        this->sz=sz;
    }
};
node* solve(TreeNode<int>* root, int &res)
{
    if(root==NULL){
        return new node(1e9,-1e9,0);
    }
    node* l = solve(root->left,res);
    node* r = solve(root->right,res);
    if(root->data>l->mx&&root->data<r->mn){
        res=max(res,l->sz+r->sz+1);
        return new node(min(l->mn,root->data),max(r->mx,root->data),l->sz+r->sz+1);
    }
    return new node(-1e9,1e9,max(l->sz,r->sz));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int res=0;
    solve(root,res);
    return res;
}
