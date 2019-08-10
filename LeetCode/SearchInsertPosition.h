#pragma once
#include"stdafx.h"

using namespace std;

//35. Search Insert Position
//https://leetcode.com/problems/search-insert-position/

namespace p35
{
	class Solution
	{
	public:
		int searchInsert(vector<int>& nums, int target)
		{
			int r = nums.size() - 1;
			int l = 0;
			int m;
			while (l < r)
			{
				m = (r - l) / 2 + l;

				if (target > nums[m])
				{
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}

			return l;
		}
	};
}