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
void solve(TreeNode<int>*root, int height, int &cnt, vector<int>&v)
{
    if(root==NULL)return;
    if(height==cnt){
        v.push_back(root->data);
        cnt++;
    }
    solve(root->left,height+1,cnt,v);
    solve(root->right,height+1,cnt,v);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int>v;
    int cnt=0;
    solve(root,0,cnt,v);
    return v;
}
