#pragma once
#include"stdafx.h"

using namespace std;

//113. Path Sum II
//https://leetcode.com/problems/path-sum-ii/
namespace p113
{
	class Solution
	{
	public:
		vector<vector<int>> pathSum(TreeNode* root, int sum)
		{
			vector<vector<int>> res;
			vector<int> path;

			dfs(res, path, sum, root);
			return res;

		}
		void dfs(vector<vector<int>>&vec, vector<int> path, int sum, TreeNode* node)
		{
			if (!node)
				return;

			path.push_back(node->val);

			if (node->val == sum && !node->left && !node->right)
			{
				vec.push_back(path);
			}

			dfs(vec, path, sum - node->val, node->left);
			dfs(vec, path, sum - node->val, node->right);

			path.pop_back();
		}

	};
}