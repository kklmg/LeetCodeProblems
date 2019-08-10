#pragma once
#include"stdafx.h"

using namespace std;

//653. Two Sum IV - Input is a BST
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

namespace p653
{
	class Solution
	{
	public:
		bool findTarget(TreeNode* root, int k)
		{
			unordered_set<int> table;
			return Helper(root, k, table);
		}
		bool Helper(TreeNode* root, int k, unordered_set<int>&table)
		{
			if (!root)return false;
			if ((table.count(k - root->val)))
				return true;
			else
				table.insert(root->val);
			return Helper(root->right, k, table) || Helper(root->left, k, table);
		}
	};
}