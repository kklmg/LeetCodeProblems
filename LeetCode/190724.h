#pragma once
#include"stdafx.h"

using namespace std;



//107. Binary Tree Level Order Traversal II
//https://leetcode.com/problemset/all/
class Solution 
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) 
	{
		vector<vector<int>> res;
	
		if (!root)
			return res;
	
		dfs(res, root, 0);

		reverse(res.begin(), res.end());

		return res;
	}

	void dfs(vector<vector<int>>&vec, TreeNode* root,int lv)
	{
		if (!root)
			return;
				
		dfs(vec, root->left, lv + 1);
		dfs(vec, root->right, lv + 1);
		
		if (lv > vec.size()) 
		{
			vec.resize(lv);
		}
		vec[lv].push_back(root->val);
	}

	
};