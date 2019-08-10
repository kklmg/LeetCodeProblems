#pragma once
#include"stdafx.h"

using namespace std;


//623. Add One Row to Tree
//https://leetcode.com/problems/add-one-row-to-tree/

namespace p623
{
	class Solution
	{
	public:
		TreeNode* addOneRow(TreeNode* root, int v, int d)
		{
			if (d == 1)
			{
				TreeNode* NewNode = new TreeNode(v);
				NewNode->left = root;
				return NewNode;
			}

			queue<TreeNode*>que;

			que.push(root);
			int qsize, curDepth = 0, i;
			TreeNode* curNode;
			while (!que.empty())
			{
				qsize = que.size();
				++curDepth;

				if (curDepth != d - 1)
				{
					for (i = 0; i < qsize; ++i)
					{
						curNode = que.front();
						que.pop();

						if (curNode->left)que.push(curNode->left);
						if (curNode->right)que.push(curNode->right);
					}
				}
				else
				{
					for (i = 0; i < qsize; ++i)
					{
						curNode = que.front();
						que.pop();

						TreeNode* newnodeL = new TreeNode(v);
						TreeNode* newnodeR = new TreeNode(v);

						newnodeL->left = curNode->left;
						curNode->left = newnodeL;

						newnodeR->right = curNode->right;
						curNode->right = newnodeR;
					}
					return root;
				}
			}
		}
	};
}