#pragma once
#include"stdafx.h"

using namespace std;


//141. Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/

class Solution
{
public:
	bool hasCycle(ListNode *head)
	{
		ListNode* Slow = head;
		ListNode* fast = head;

		while (fast)
		{
			if(fast->next)
			fast = fast->next->next;
			else return nullptr;

			Slow = Slow->next;

			if (Slow == fast)return true;
		}
		return false;
	}
};
