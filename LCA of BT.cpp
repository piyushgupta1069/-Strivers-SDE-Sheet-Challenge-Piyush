#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>*solve(TreeNode<int>*root, int x, int y){
    if(root==NULL||root->data==x||root->data==y)return root;
    TreeNode<int>*l = solve(root->left, x, y);
    TreeNode<int>*r = solve(root->right, x, y);
    if(l==NULL)return r;
    else if(r==NULL)return l;
    else return root;
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    return solve(root,x,y)->data;
}
