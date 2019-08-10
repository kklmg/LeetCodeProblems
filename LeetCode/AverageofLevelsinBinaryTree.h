#pragma once
#include"stdafx.h"

using namespace std;


//637. Average of Levels in Binary Tree
//https://leetcode.com/problems/average-of-levels-in-binary-tree/
namespace p637
{
	class Solution
	{
	public:
		vector<double> averageOfLevels(TreeNode* root)
		{
			if (!root)
				return{};

			vector<double>res;
			queue<TreeNode*> que;

			que.push(root);

			TreeNode* Cur;
			int count, i, sum;


			while (!que.empty())
			{
				sum = 0;
				for (int i = 0; i < count; ++i)
				{
					Cur = que.front();
					que.pop();
					sum += Cur->val;

					if (Cur->left)
						que.push(Cur->left);
					if (Cur->right)
						que.push(Cur->right);
				}
				res.push_back(sum / count);
			}
			return res;
		}
	};
}