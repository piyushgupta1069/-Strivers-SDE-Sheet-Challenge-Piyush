#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    int res=0;
    if(root==NULL)return res;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        res=max(res,sz);
        for(int i=0;i<sz;i++){
            auto node = q.front();
            q.pop();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
    }
    return res;
}
