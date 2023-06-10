#include "bits/stdc++.h"
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* solve(int il, int ir, int pl, int pr, vector<int>&inorder, vector<int>&postorder, map<int,int>&m)
{
     if(il>ir||pl>pr)return NULL;
     int ind = postorder[pr];
     TreeNode<int>* node = new TreeNode<int>(ind);
     node->left = solve(il,m[ind]-1,pl,pl+(m[ind]-il-1),inorder,postorder,m);
     node->right = solve(m[ind]+1,ir,pl+m[ind]-il,pr-1,inorder,postorder,m);
     return node;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
     map<int,int>m;
     for(int i=0;i<inorder.size();i++)
     {
          m[inorder[i]]=i;
     }
     return solve(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder,m);
}
