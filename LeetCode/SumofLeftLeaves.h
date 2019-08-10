#pragma once
#include"stdafx.h"

using namespace std;

//404. Sum of Left Leaves
//https://leetcode.com/problems/sum-of-left-leaves/

namespace p404
{
	class Solution
	{
	public:
		int sumOfLeftLeaves(TreeNode* root)
		{
			if (!root)
				return 0;
			if (!root->left)
				return 0;
			if (!root->left->left && !root->left->right)
			{
				return root->left->val;
			}

			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
		}
	};
}