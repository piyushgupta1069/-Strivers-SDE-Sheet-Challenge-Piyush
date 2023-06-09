#include <bits/stdc++.h> 
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    queue<pair<TreeNode<int>*,int>>q;
    map<int,vector<int>>m;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        m[it.second].push_back(it.first->data);
        if(it.first->left)q.push({it.first->left,it.second-1});
        if(it.first->right)q.push({it.first->right,it.second+1});
    }
    vector<int>res;
    for(auto it:m){
        for(auto i:it.second){
            res.push_back(i);
        }
    }
    return res;

}
