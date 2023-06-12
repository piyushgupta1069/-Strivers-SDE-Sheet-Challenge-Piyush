#include "bits/stdc++.h"
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

string serializeTree(TreeNode<int> *root)
{

    //    Write your code here for serializing the tree
    string res;
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz;i++){
            auto node = q.front();
            q.pop();
            if(node==NULL){
                res+="#,";
            }else{
                res+=(to_string(node->data));
                res+=',';
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
    return res;

}

TreeNode<int>* deserializeTree(string &serialized)
{
    //    Write your code here for deserializing the tree
    vector<int>v;
    for(int i=0;i<serialized.size();)
    {
        string t;
        while(i<serialized.size()&&serialized[i]!=','){
            t+=serialized[i];
            i++;
        }
        i++;
        if(t=="#")v.push_back(-1);
        else v.push_back(stoi(t));
    }
    if(v[0]==-1)return NULL;
    queue<TreeNode<int>*>q;
    int ind=0;
    TreeNode<int>* root = new TreeNode<int>(v[ind]);
    ind++;
    q.push(root);
    while(ind<v.size()){
        auto node = q.front();
        q.pop();
        if(v[ind]==-1){
            node->left=NULL;
        }else{
            node->left = new TreeNode<int>(v[ind]);
            q.push(node->left);
        }
        ind++;
        if(v[ind]==-1){
            node->right=NULL;
        }else{
            node->right=new TreeNode<int>(v[ind]);
            q.push(node->right);
        }
        ind++;
    }
    return root;

}



