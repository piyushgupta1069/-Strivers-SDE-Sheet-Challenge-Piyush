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
TreeNode<int>* solve(int il, int ir, int pl, int pr, vector<int>&preorder, vector<int>&inorder, map<int,int>&m)
{
    if(il>ir||pl>pr)return NULL;
    TreeNode<int>* node = new TreeNode<int>(preorder[pl]);
    int ind = m[preorder[pl]];
    node->left = solve(il,ind-1,pl+1,pl+ind-il,preorder,inorder,m);
    node->right = solve(ind+1,ir,pl+ind-il+1,pr,preorder,inorder,m);
    return node;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    map<int,int>m;
    int n = preorder.size();
    for(int i=0;i<n;i++){
        m[inorder[i]]=i;
    }
    return solve(0,n-1,0,n-1,preorder,inorder,m);
}
