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

void solve(TreeNode<int>* root, int &k, int &ans)
{
    if(root==NULL)return;
    solve(root->left,k,ans);
    k--;
    if(k==0){
        ans=root->data;
        return;
    }
    solve(root->right,k,ans);

}
int kthSmallest(TreeNode<int>* root, int k) {
    int ans;
    solve(root,k,ans);
    return ans;
}
