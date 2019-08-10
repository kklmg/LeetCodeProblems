#pragma once
#include"stdafx.h"

using namespace std;

//109. Convert Sorted List to Binary Search Tree
//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

namespace p109
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