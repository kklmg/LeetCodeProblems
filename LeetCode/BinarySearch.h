#pragma once
#include"stdafx.h"

using namespace std;


//704. Binary Search
//https://leetcode.com/problems/binary-search/

namespace p704
{
	class Solution
	{
	public:
		int search(vector<int>& nums, int target)
		{
			int l = 0, r = nums.size() - 1;
			int mid;

			while (l < r)
			{
				mid = (l + r) / 2;

				if (nums[mid] == target)
					return mid;

				if (nums[mid] < target)
				{
					l = mid + 1;
				}
				else
					r = mid;
			}
			return -1;
		}
	};
}