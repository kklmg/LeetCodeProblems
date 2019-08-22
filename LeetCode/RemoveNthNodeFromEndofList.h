#pragma once
#include"stdafx.h"

using namespace std;

//19. Remove Nth Node From End of List
//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution 
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{		
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode dummy(0);
		dummy.next = head;

		ListNode* par = &dummy;

		while (n)
		{
			fast = fast->next;
			--n;
		}

		while (fast)
		{
			par = slow;
			fast = fast->next;
			slow = slow->next;
		}

		par->next = slow->next;
		delete slow;

		return dummy.next;
	}
};
