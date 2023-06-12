#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void solve(BinaryTreeNode<int>*root, int X, int &ans)
{
    if(root==NULL)return;
    if (root->data >= X) {
      ans = min(ans, root->data);
      solve(root->left, X, ans);
    } 
    else
      solve(root->right, X, ans);
}
int findCeil(BinaryTreeNode<int> *node, int X){
    // Write your code here.
    int ans=2e9;
    solve(node,X,ans);
    return ans==2e9?-1:ans;
}
