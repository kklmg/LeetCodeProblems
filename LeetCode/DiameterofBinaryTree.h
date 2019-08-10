#pragma once
#include"stdafx.h"

using namespace std;

//543. Diameter of Binary Tree
//https://leetcode.com/problems/diameter-of-binary-tree/

namespace p543
{
	class Solution
	{
	public:
		int diameterOfBinaryTree(TreeNode* root)
		{
			int maxDepth = 0;

			getlength(root, maxDepth);
			return maxDepth;
		}

		int getlength(TreeNode* root, int maxdepth)
		{
			if (!root)
				return 0;
			int left = getlength(root->left, maxdepth);
			int right = getlength(root->right, maxdepth);

			maxdepth = max(maxdepth, left + right + 1);

			return max(left, right) + 1;
		}
	};
}