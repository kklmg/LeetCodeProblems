#pragma once
#include"stdafx.h"

using namespace std;

//99. Recover Binary Search Tree
//https://leetcode.com/problems/recover-binary-search-tree/

namespace p99
{
	class Solution
	{
	public:
		void recoverTree(TreeNode* root)
		{
		}

		TreeNode* GetWrongNode(TreeNode* root)
		{
			if (!root)
				return nullptr;

			if (root->left->val > root->val)
				return root->left;

			if (root->right->val < root->val)
				return root->left;

			GetWrongNode(root->left);
			GetWrongNode(root->right);

			root->left;
		}
	};
}