#pragma once
#include"stdafx.h"

using namespace std;

//108. Convert Sorted Array to Binary Search Tree
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
namespace p108
{
	class Solution
	{
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums)
		{
			int size = nums.size();
			if (!size)
				return nullptr;

			int mid = (size - 1) / 2;

			TreeNode* root;
			root = new TreeNode(nums[mid]);
			helper(nums, &root, 0, size - 1);

			return root;
		}
		void helper(vector<int>& nums, TreeNode**node, int l, int r)
		{
			if (l > r)
				return;
			int mid = (l + r) / 2 + 1;

			*node = new TreeNode(nums[mid]);

			helper(nums, &((*node)->left), l, mid - 1);
			helper(nums, &((*node)->right), mid + 1, r);
		}
	};
}