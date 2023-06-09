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
int solve(TreeNode<int>*root, int &res)
{
    if(root==NULL)return 0;
    int l = solve(root->left,res);
    int r = solve(root->right,res);
    res = max(res,l+r);
    return max(l,r)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int res=0;
    solve(root,res);
    return res;
}
