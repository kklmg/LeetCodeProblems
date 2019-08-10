#pragma once
#include"stdafx.h"

using namespace std;

//124. Binary Tree Maximum Path Sum
//https://leetcode.com/problems/binary-tree-maximum-path-sum/

namespace p124
{
	class Solution
	{
	public:
		int maxPathSum(TreeNode* root)
		{
			int sum = INT_MIN;

			helper(sum, root);

			return sum;
		}

		int helper(int &sum, TreeNode*root)
		{
			if (!root)
				return 0;

			int maxleft = max(0, helper(sum, root->left));
			int maxright = max(0, helper(sum, root->right));

			sum = max(sum, maxleft + maxright + root->val);

			return
				maxleft > maxright ? maxleft + root->val : maxright + root->val;
		}
	};
}