#pragma once
#include"stdafx.h"

using namespace std;

//129. Sum Root to Leaf Numbers
//https://leetcode.com/problems/sum-root-to-leaf-numbers/

namespace p129
{
	class Solution
	{
	public:
		int sumNumbers(TreeNode* root)
		{
			return Helper(root, 0);
		}
		int Helper(TreeNode* root, int sum)
		{
			if (!root)
				return 0;

			if (!root->left && !root->right)
				return sum * 10 + root->val;

			return
				Helper(root->left, sum * 10 + root->val) +
				Helper(root->right, sum * 10 + root->val);
		}

	};
}
