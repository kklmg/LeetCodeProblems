#pragma once
#include"stdafx.h"

using namespace std;

//235. Lowest Common Ancestor of a Binary Search Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

namespace p235
{
	class Solution
	{
	public:
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
		{
			if (root->val > p->val && root->val > q->val)
			{
				return lowestCommonAncestor(root->left, p, q);
			}
			else if (root->val < p->val && root->val < q->val)
			{
				return lowestCommonAncestor(root->right, p, q);
			}

			else return root;
		}
	};
}

