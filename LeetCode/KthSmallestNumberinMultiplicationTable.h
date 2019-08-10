#pragma once
#include"stdafx.h"

using namespace std;

//668. Kth Smallest Number in Multiplication Table
//https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

namespace p268
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
				ct = ComputeCount(m, n, mid);

				if (ct >= k)
				{
					high = mid;
				}
				else
				{
					low = mid + 1;
				}
			}
			return high;
		}
		int ComputeCount(int Row, int Column, int target)
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
