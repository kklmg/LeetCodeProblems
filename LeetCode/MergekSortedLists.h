#pragma once
#include"stdafx.h"

using namespace std;

struct Compare 
{
	bool operator()(const ListNode*a, const ListNode*b) 
	{
		return a->val < b->val;
	}
};

class Solution
{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

		for (ListNode* node : lists) 
		{
			pq.push(node);
		}
	
		if (!pq.size())return nullptr;

		ListNode *head = pq.top();
		pq.pop();
		if (head->next) pq.push(head->next);

		ListNode *tail = head;
		ListNode *Cur;
		

		while (!pq.empty())
		{
			tail->next = pq.top();
			pq.pop();

			tail = tail->next;

			if (tail->next)
				pq.push(tail->next);
		}
		return head;

	}
};