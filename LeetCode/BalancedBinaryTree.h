#pragma once
#include"stdafx.h"

using namespace std;

//110. Balanced Binary Tree
//https://leetcode.com/problems/balanced-binary-tree/

namespace p110
{
	class Solution
	{
	public:
		bool isBalanced(TreeNode* root)
		{
			if (!root)
				return true;

			bool isbalance = true;

			helper(root, isbalance);
			return isbalance;
		}

		int helper(TreeNode* root, bool& isbalance)
		{
			int l = helper(root->left, isbalance);
			int r = helper(root->right, isbalance);

			if (abs(l - r) > 1)
			{
				isbalance = false;
			}

			return 1 + max(l, r);
		}

	};
}
