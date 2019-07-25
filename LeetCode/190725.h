#pragma once
#include"stdafx.h"

using namespace std;

//103. Binary Tree Zigzag Level Order Traversal
//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
namespace problem103
{
	class Solution
	{
	public:
		vector<vector<int>> zigzagLevelOrder(TreeNode* root)
		{
			vector<vector<int>>res;

			queue<TreeNode*>que;

			TreeNode* cur;
			if (root)
				que.push(root);

			int i, count, level = 0;
			bool flag = true;

			while (!que.empty())
			{

				flag = !flag;
				count = que.size();
				res.push_back(vector<int>(count));

				for (i = 0; i < count; ++i)
				{
					cur = que.front();
					que.pop();

					if (flag)
						res[level][i] = cur->val;
					else
						res[level][count - i] = cur->val;

					if (cur->left)
						que.push(cur->left);
					if (cur->right)
						que.push(cur->right);
				}

				++level;
			}
			return res;
		}
	};
}

//108. Convert Sorted Array to Binary Search Tree
//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
namespace problem108
{
	class Solution
	{
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums)
		{
			int size = nums.size();
			if (!size)
				return nullptr;

			int mid = (size - 1) / 2;

			TreeNode* root;
			root = new TreeNode(nums[mid]);
			helper(nums, &root, 0, size - 1);

			return root;
		}
		void helper(vector<int>& nums, TreeNode**node, int l, int r)
		{
			if (l > r)
				return;
			int mid = (l + r) / 2 + 1;

			*node = new TreeNode(nums[mid]);

			helper(nums, &((*node)->left), l, mid - 1);
			helper(nums, &((*node)->right), mid + 1, r);
		}
	};
}


//109. Convert Sorted List to Binary Search Tree
//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

namespace problem109
{
	class Solution
	{
	public:
		TreeNode* sortedListToBST(ListNode* head)
		{
			if (!head) return nullptr;
			if (!head->next) return new TreeNode(head->val);

			ListNode* slow = head;
			ListNode* fast = head->next;

			while (fast->next && fast->next->next)
			{
				fast = fast->next->next;
				slow = slow->next;
			}

			TreeNode* newnode = new TreeNode(slow->next->val);


			ListNode* temp = slow->next;
			slow->next = nullptr;

			newnode->left = sortedListToBST(head);
			newnode->right = sortedListToBST(temp->next);

			return newnode;
		}
	};
	void test() 
	{
		ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
		n1.next = &n2;
		n2.next = &n3;
		n3.next = &n4;
		n4.next = &n5;		
		

		Solution s;
		
	
		TreeNode *result = s.sortedListToBST(&n1);
	}

}

//110. Balanced Binary Tree
//https://leetcode.com/problems/balanced-binary-tree/

namespace problem110
{
	class Solution
	{
	public:
		bool isBalanced(TreeNode* root) 
		{
			if (!root)
				return true;

			bool isbalance = true;

			helper(root, isbalance);
			return isbalance;
		}

		int helper(TreeNode* root,bool& isbalance) 
		{
			int l = helper(root->left,isbalance);
			int r = helper(root->right, isbalance);

			if (abs(l - r) > 1) 
			{
				isbalance = false;
			}

			return 1 + max(l, r);
		}
	
	};
}


//111. Minimum Depth of Binary Tree
//https://leetcode.com/problems/minimum-depth-of-binary-tree/

namespace problem111
{
	class Solution
	{
	public:
		int minDepth(TreeNode* root)
		{
			if (!root)return 0;
			return 1+min( minDepth(root->left),minDepth(root->right));
		}
	};
}

//113. Path Sum II
//https://leetcode.com/problems/path-sum-ii/
namespace problem111
{
	class Solution 
	{
	public:
		vector<vector<int>> pathSum(TreeNode* root, int sum) 
		{
			vector<vector<int>> res;
			vector<int> path;

			dfs(res,path,sum,root);
			return res;

		}
		void dfs(vector<vector<int>>&vec, vector<int> path,int sum, TreeNode* node)
		{
			if (!node)
				return;

			path.push_back(node->val);

			if (node->val == sum && !node->left && !node->right)
			{
				vec.push_back(path);	
			}

			dfs(vec, path, sum - node->val, node->left);
			dfs(vec, path, sum - node->val, node->right);
		
			path.pop_back();
		}

	};
}

//114. Flatten Binary Tree to Linked List
//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

namespace problem114
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


////120. Triangle
////https://leetcode.com/problems/triangle/
//
//namespace problem120
//{
//	class Solution 
//	{
//	public:
//		int minimumTotal(vector<vector<int>>& triangle) 
//		{
//			int size = triangle.size();
//			int i = 0;
//
//		}
//	};
//
//
//}