#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool solve(TreeNode<int>*root, vector<int>&res, int x)
{
	if(root==NULL)return false;
	res.push_back(root->data);
	
	if(root->data==x){
		return true;
	}
	
	if(solve(root->left,res,x))return true;
	if(solve(root->right,res,x))return true;
	res.pop_back();
	return false;

}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>res;
	solve(root,res,x);
	return res;
}
