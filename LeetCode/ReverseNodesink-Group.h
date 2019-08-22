#pragma once
#include"stdafx.h"

using namespace std;

//25. Reverse Nodes in k - Group
//https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution 
{
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		ListNode *Cur = head;
		ListNode *Par = Cur;
		ListNode *Next = Cur->next;

		while (Next)
		{
			for (int i = 0; i < k && Next; ++i)
			{
				Par = Cur;
				Cur = Next;
				Next = Cur->next;			
				Cur->next = Par;
			}
		}
		Next->next = Cur;

		return Next;

	}
};