#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
int cnt=0;
long long int solve(TreeNode<int>*root, long long int &res)
{
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)cnt++;
    long long int l = solve(root->left,res);
    long long int r = solve(root->right,res);
    res=max(res,l+r+root->val);
    return max(l,r)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)return -1;
    long long int res=0;
    cnt=0;
    solve(root,res);
    if(cnt==1)return -1;
    return res;
}
