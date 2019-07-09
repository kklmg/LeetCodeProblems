#pragma once
//Search a 2D Matrix II

//Write an efficient algorithm that searches for a value in an m x n matrix.
//This matrix has the following properties :
//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

//https://leetcode.com/explore/learn/card/recursion-ii/470/divide-and-conquer/2872/

using namespace std;




//F(0) = 0, F(1) = 1
//F(N) = F(N - 1) + F(N - 2), for N > 1.
//class Solution
//{
//public:
//	void flatten(TreeNode* root)
//	{
//		if (!root)return;
//
//		flatten(root->left);
//		flatten(root->right);
//
//		if (root->left)
//		{
//			root->right = root->left;
//			root->left->right = root->right;
//		}
//		else
//			root->left = nullptr;
//	}
//
//
//};
