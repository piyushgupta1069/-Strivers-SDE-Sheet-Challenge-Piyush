#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* solve(int l, int r, vector<int>&preOrder, int &index)
{
    if(index>=preOrder.size()||preOrder[index]<l||preOrder[index]>r)return NULL;
    TreeNode<int>* root = new TreeNode<int>(preOrder[index]);
    index++;
    root->left=solve(l,preOrder[index-1]-1,preOrder,index);
    root->right=solve(preOrder[index-1]+1,r,preOrder,index);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int index=0;
    return solve(-1e9,1e9,preOrder,index);
}
