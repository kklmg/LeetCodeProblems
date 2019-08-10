#pragma once
#include"..\stdafx.h"

//1038. Binary Search Tree to Greater Sum Tree
//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

namespace p1038
{
	class Solution
	{
	public:
		TreeNode* bstToGst(TreeNode* root)
		{
			if (root->right) bstToGst(root->right);
			root->val = temp = root->val + temp;
			if (root->left) bstToGst(root->left);
			return root;
		}
		int temp = 0;
	};
}