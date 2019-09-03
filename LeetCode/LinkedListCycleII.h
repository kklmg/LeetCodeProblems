#pragma once
#include"stdafx.h"

using namespace std;

//142. Linked List Cycle II
//https://leetcode.com/problems/linked-list-cycle-ii/

class Solution
{
public:
	ListNode *detectCycle(ListNode *head)
	{
		ListNode* Slow = head;
		ListNode* fast = head;
		bool hascycle = false;
		while (fast)
		{
			if (fast->next)
				fast = fast->next->next;
			Slow = Slow->next;

			if (Slow == fast) 
			{
				hascycle = true;
				break;
			};
		}
		if (!hascycle)return nullptr;

		Slow = head;

		while (Slow ==fast)
		{
			Slow = Slow->next;
			fast = fast->next;
		}
		return Slow;

	}
};