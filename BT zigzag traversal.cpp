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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int>res;
    if(root==NULL)return res;
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    int f=1;
    while(!q.empty()){
        int sz = q.size();
        vector<int>v;
        for(int i=0;i<sz;i++){
            auto node = q.front();
            q.pop();
            v.push_back(node->data);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        if(!f)reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            res.push_back(v[i]);
        }
        f=1-f;
    }
    return res;
}
