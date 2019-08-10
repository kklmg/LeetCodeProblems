#pragma once
#include"stdafx.h"

using namespace std;

//1046. Last Stone Weight
//https://leetcode.com/problems/last-stone-weight/

namespace p1046
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