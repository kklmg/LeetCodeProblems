#pragma once
#include"stdafx.h"

using namespace std;

//103. Binary Tree Zigzag Level Order Traversal
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
namespace p103
{
	class Solution
	{
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root)
		{
			vector<vector<int>>res;

			queue<TreeNode*>que;

			TreeNode* cur;
			if (root)
				que.push(root);

			int i, count, level = 0;
			bool flag = true;

			while (!que.empty())
			{

				flag = !flag;
				count = que.size();
				res.push_back(vector<int>(count));

				for (i = 0; i < count; ++i)
				{
					cur = que.front();
					que.pop();

					if (flag)
						res[level][i] = cur->val;
					else
						res[level][count - i] = cur->val;

					if (cur->left)
						que.push(cur->left);
					if (cur->right)
						que.push(cur->right);
				}

				++level;
			}
			return res;
		}
	};
}