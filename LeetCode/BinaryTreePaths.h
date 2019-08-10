#pragma once
#include"stdafx.h"

using namespace std;

//257. Binary Tree Paths
//https://leetcode.com/problems/binary-tree-paths/

namespace p257
{
	class Solution
	{
	public:
		vector<string> binaryTreePaths(TreeNode* root)
		{
			vector<string> res;

			Helper(res, "", root);
			return res;
		}

		void Helper(vector<string>&res, string curpath, TreeNode* root)
		{
			if (!root)
				return;


			if (!root->left && !root->right)
			{
				res.push_back(curpath + "->" + to_string(root->val));
			}
			Helper(res, curpath + "->" + to_string(root->val), root->left);
			Helper(res, curpath + "->" + to_string(root->val), root->right);
		}
	};
}