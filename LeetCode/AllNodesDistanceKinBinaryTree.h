#pragma once
#include"stdafx.h"

using namespace std;

//863. All Nodes Distance K in Binary Tree
//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
namespace p863
{
	class Solution
	{
	public:
		vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
		{
			unordered_map<TreeNode*, TreeNode*> table;

			vector<int> res;

			TreeNode* tar;
			helper(table, root, target->val, &tar);


			queue<TreeNode*>que;
			que.push(tar);
			int layer = 0, qsize, i;
			while (!que.empty())
			{
				layer++;

				if (layer == K)
				{
					res.reserve(que.size());
					while (!que.empty())
					{
						res.push_back(que.front()->val);
						que.pop();
					}
				}

				qsize = que.size();
				for (i = 0; i < qsize; ++i)
				{
					tar = que.front();
					que.pop();

					if (tar->left)que.push(tar->left);
					if (tar->right)que.push(tar->right);
					if (table[tar])que.push(table[tar]);
				}
			}


		}

		void helper(unordered_map<TreeNode*, TreeNode*>&table, TreeNode* node, int target, TreeNode** tarnode)
		{
			if (node->val == target)
			{
				*tarnode = node;
				return;
			}

			if (node->left)
				table[node->left] = node;
			if (node->right)
				table[node->left] = node;

			helper(table, node->left, target, tarnode);
			helper(table, node->right, target, tarnode);
		}
	};
}