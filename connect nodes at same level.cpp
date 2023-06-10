#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode<int>*>q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        for(int i=0;i<sz-1;i++){
            auto node = q.front();
            q.pop();
            node->next=q.front();
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        auto node = q.front();
        q.pop();
        node->next=NULL;
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
    
}
