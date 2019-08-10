#pragma once
#include"stdafx.h"

using namespace std;

//111. Minimum Depth of Binary Tree
//https://leetcode.com/problems/minimum-depth-of-binary-tree/

namespace p111
{
	class Solution
	{
	public:
		int minDepth(TreeNode* root)
		{
			if (!root)return 0;
			return 1 + min(minDepth(root->left), minDepth(root->right));
		}
	};
}
