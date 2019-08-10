#pragma once
#include"stdafx.h"

using namespace std;

//199. Binary Tree Right Side View
//https://leetcode.com/problems/binary-tree-right-side-view/
class Solution
{
public:
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int>res;

		queue<TreeNode*>que;
		que.push(root);

		TreeNode* cur;
		int i, count;
		while (!que.empty())
		{
			count = que.size();
			res.push_back(que.back()->val);

			for (i = 0; i < count; ++i)
			{
				cur = que.front();

				que.pop();

				if (cur->left)que.push(cur->left);
				if (cur->right)que.push(cur->right);
			}
		}

		return res;
	}
};