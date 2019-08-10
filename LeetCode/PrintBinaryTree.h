#pragma once
#include"stdafx.h"

using namespace std;

//655. Print Binary Tree
//https://leetcode.com/problems/print-binary-tree/

namespace p655
{
	class Solution
	{
	public:
		vector<vector<string>> printTree(TreeNode* root)
		{
			int height = GetHeight(root);

			int width = pow(2, height) - 1;

			vector<vector<string>> result(height, vector<string>(width, ""));

			fillvector(root, result, 0, 0, width - 1);

			return result;
		}

		int GetHeight(TreeNode* root)
		{
			if (!root)return 0;

			return 1 + max(GetHeight(root->left), GetHeight(root->right));
		}

		void fillvector(TreeNode* root, vector<vector<string>>&vec, int depth, int left, int right)
		{
			if (!root) return;
			int mid = (right + left) / 2;

			vec[depth][mid] = to_string(root->val);

			fillvector(root->left, vec, depth + 1, left, mid - 1);
			fillvector(root->right, vec, depth + 1, mid + 1, right);
		}
	};
}
