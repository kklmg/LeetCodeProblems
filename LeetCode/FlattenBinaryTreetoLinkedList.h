#pragma once
#include"stdafx.h"

using namespace std;


//114. Flatten Binary Tree to Linked List
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

namespace p114
{
	class Solution
	{
	public:
		void flatten(TreeNode* root)
		{
		
			if (!root)return;


			flatten(root->left);
			flatten(root->right);

			if (root->right && root->left) 
			{
				TreeNode* temp = root->right;
				root->right = root->left;

				TreeNode *ter = root->right;
				while (ter->right)
				{
					ter = ter->right;
				}
				ter->right = temp;
			
				root->left = nullptr;
			}

			else if (root->left) 
			{
				root->right = root->left;
				root->left = nullptr;
			
			}
		}
	};
}


