#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

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
void solve(TreeNode<int>* root, int width, int height, map<int,pair<int,int>>&m)
{
    if(root==NULL)return;
    if(m.count(width)){
        if(m[width].second>height){
            m[width]={root->val,height};
        }
    }else m[width]={root->val,height};
    solve(root->left,width-1,height+1,m);
    solve(root->right,width+1,height+1,m);
}
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    map<int,pair<int,int>>m;
    solve(root,0,0,m);
    vector<int>res;
    for(auto it:m){
        res.push_back(it.second.first);
    }
    return res;
}
