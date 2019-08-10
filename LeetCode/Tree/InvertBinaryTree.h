#pragma once

#include"../stdafx.h"
using namespace std;

//226. Invert Binary Tree
//https://leetcode.com/problems/invert-binary-tree/

class Solution
{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if (!root)
			return nullptr;

		TreeNode *Temp = root->left;
		root->left = invertTree(root->right);
		root->right = invertTree(Temp);

		return root;
	}
};