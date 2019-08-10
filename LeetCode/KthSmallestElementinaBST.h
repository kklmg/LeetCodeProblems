#pragma once
#include"stdafx.h"

using namespace std;

//230. Kth Smallest Element in a BST
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
namespace p230
{
	class Solution
	{
	public:
		int kthSmallest(TreeNode* root, int k)
		{
			int l;
			while (root)
			{
				l = count(root->left);
				if (l > k)
					root = root->left;
				else
				{
					root = root->right;
					k = k - l;
				}
				if (l == k)
					return root->val;
			}
			return 0;
		}

		int count(TreeNode* node)
		{
			if (!node)return 0;

			return 1 + count(node->left) + count(node->right);
		}

	};

	class Solution2
	{
	public:
		int kthSmallest(TreeNode* root, int k)
		{
			int res;

			count(root, res, k);

			return res;
		}

		int count(TreeNode* node, int &res, int &k)
		{
			if (!node)
				return INT_MIN;

			int n = count(node->left, res, k);

			if (n == k)
				res = node->val;

			else
				count(node->right, res, k);
		}

	};
}