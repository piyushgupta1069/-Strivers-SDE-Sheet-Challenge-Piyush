#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure.

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
void solve(BinaryTreeNode<int>* root, int width, int height, map<int,pair<int,int>>&m)
{
    if(root==NULL)return;
    if(m.count(width)){
        if(m[width].second<=height){
            m[width]={root->data,height};
        }
    }else m[width]={root->data,height};
    solve(root->left,width-1,height+1,m);
    solve(root->right,width+1,height+1,m);
}
vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    map<int,pair<int,int>>m;
    solve(root,0,0,m);
    vector<int>res;
    for(auto it:m){
        res.push_back(it.second.first);
    }
    return res;
    
}
