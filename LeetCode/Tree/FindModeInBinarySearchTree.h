#pragma once
#include"..\stdafx.h"

using namespace std;

//501. Find Mode in Binary Search Tree
//https://leetcode.com/problems/find-mode-in-binary-search-tree/

namespace p501
{
	class Solution
	{
	public:
		vector<int> findMode(TreeNode* root)
		{
			unordered_map<int, int>counter;
			vector<int>result;

			int max = getmax(root, counter);

			for (auto iter : counter)
			{
				if (max == iter.second)
					result.push_back(iter.first);
			}
			return result;

		}
		int getmax(TreeNode* root, unordered_map<int, int>&_map)
		{
			if (!root)
				return 0;

			_map[root->val]++;

			return max(_map[root->val],
				max(getmax(root->left, _map), getmax(root->right, _map)));
		}

	};
}