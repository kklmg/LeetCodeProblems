#pragma once
#include"stdafx.h"

using namespace std;

//872. Leaf-Similar Trees	
//https://leetcode.com/problems/leaf-similar-trees/

namespace p872
{
	class Solution
	{
	public:
		bool leafSimilar(TreeNode* root1, TreeNode* root2)
		{
			vector<int> seq1, seq2;

			DFS(root1, seq1);
			DFS(root2, seq2);

			return seq1 == seq2;

		}

		void DFS(TreeNode* root, vector<int>& vec)
		{
			if (!root)return;

			if (!root->left && !root->right)
			{
				vec.push_back(root->val);
			}

			DFS(root->left, vec);
			DFS(root->right, vec);
		}
	};
}