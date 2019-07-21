#pragma once

#include"stdafx.h"

using namespace std;

//668. Kth Smallest Number in Multiplication Table
//https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/


namespace problem268
{
	class Solution
	{
	public:
		int findKthNumber(int m, int n, int k)
		{
			int low = 1;
			int high = m*n;

			int mid, ct;		

			while (low<high)
			{
				mid = (low + high) / 2;
				ct = ComputeCount(m, n,mid);
				
				if (ct >= k) 
				{
					high = mid;					
				}
				else
				{
					low = mid+1;
				}
			}
			return high;
		}
		int ComputeCount(int Row,int Column,int target)
		{
			int ct = 0;
			for (int i = 1; i <= Column; ++i) 
			{
				ct += min(target / i, Row);	
			}
			return ct;		
		}

	};
	void test() 
	{
		Solution s;
		int ct = s.findKthNumber(3, 3, 5);

		int test = 0;
		return;
	}
}


//655. Print Binary Tree
//https://leetcode.com/problems/print-binary-tree/

namespace problem655
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


//653. Two Sum IV - Input is a BST
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

namespace problem653
{
	class Solution
	{
	public:
		bool findTarget(TreeNode* root, int k)
		{
			unordered_set<int> table;
			return Helper(root, k, table);
		}
		bool Helper(TreeNode* root, int k, unordered_set<int>&table)
		{
			if (!root)return false;
			if ((table.count(k - root->val)))
				return true;
			else
				table.insert(root->val);
			return Helper(root->right, k, table) || Helper(root->left, k, table);
		}

	};
}