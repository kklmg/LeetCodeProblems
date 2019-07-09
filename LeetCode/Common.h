#pragma once

//common structures defined in leetcode

//list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

//tree
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};