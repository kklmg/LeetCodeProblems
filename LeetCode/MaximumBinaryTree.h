#pragma once
#include"stdafx.h"

using namespace std;

//654. Maximum Binary Tree
//https://leetcode.com/problems/maximum-binary-tree/

namespace p654
{
	class Solution
	{
	public:
		TreeNode* constructMaximumBinaryTree(vector<int>& nums)
		{
			int l = 0;
			int r = nums.size() - 1;

			int maxnum = nums[0];
			while (l < r)
			{
				//nums[++l]
			}


			return nullptr;
		}
	};
}
