#pragma once
#include"stdafx.h"

using namespace std;

//1022.Sum of Root To Leaf Binary Numbers
//https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

namespace p1022
{
	class Solution
	{
	public:
		int sumRootToLeaf(TreeNode *root)
		{
			return helper(root, 0);
		}

		int helper(TreeNode* root, int Sum)
		{
			if (!root)
				return 0;

			Sum = 2 * Sum + root->val;

			if (!root->left && !root->right)
				return Sum;

			return helper(root->left, Sum) + helper(root->right, Sum);
		}
	};
}