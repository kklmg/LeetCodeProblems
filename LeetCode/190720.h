#pragma once
#include"stdafx.h"
#include<functional>

using namespace std;
//https://leetcode.com/problems/add-two-numbers/
//2. Add Two Numbers
namespace problem2
{
	class Solution
	{
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			int carry = 0;
			ListNode dummy(0); ListNode*cur = &dummy;

			while (l1 || l2 || carry)
			{
				if (l1)
				{
					carry += l1->val;
					l1 = l1->next;

				}
				if (l2)
				{
					carry += l2->val;
					l2 = l2->next;
				}

				cur->next = new ListNode(carry % 10);
				carry /= 10;
				cur = cur->next;
			}

			return dummy.next;
		}
	};
}

//1046. Last Stone Weight
//https://leetcode.com/problems/last-stone-weight/
namespace problem1046
{
	class Solution
	{
	public:
		int lastStoneWeight(vector<int>& stones)
		{
			priority_queue<int>pq;

			int x, y;

			for (int stone : stones) 
			{
				pq.push(stone);
			}

			while (pq.size() > 1)
			{
				y = pq.top(); pq.pop();
				x = pq.top(); pq.pop();

				if (x < y) 
				{
					pq.push(y - x);
				}			
			}

			if (pq.empty())
				return 0;
			else
				return pq.top();
		}
	};
	void test() 
	{
		Solution s;
		vector<int> stones = { 2,7,4,1,8,1 };

		int n = s.lastStoneWeight(stones);
	
	}
}