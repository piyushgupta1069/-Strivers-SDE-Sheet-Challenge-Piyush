#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode* dfs(graphNode* node, map<graphNode*, graphNode*>&m)
{
	if(node==NULL)return NULL;
	if(m.find(node)!=m.end())return m[node];
	graphNode* root = new graphNode(node->data);
	m[node]=root;
	for(auto it:node->neighbours)
	{
		m[node]->neighbours.push_back(dfs(it,m));
	}
	return m[node];
}
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	map<graphNode*,graphNode*>m;
	return dfs(node,m);
}
