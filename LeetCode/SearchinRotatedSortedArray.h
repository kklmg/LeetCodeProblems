#pragma once
#include"stdafx.h"

using namespace std;

//33. Search in Rotated Sorted Array
//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int l = 0;
		int r = nums.size() - 1;
		int mid;

		while (l <= r)
		{
			mid = l + (r - l) / 2;

			if (nums[mid] == target)return mid;

			if (nums[r] < nums[mid])
			{
				if (nums[mid] < target || target <= nums[r])
				{
					l = mid + 1;
				}
				else 
				{
					r = mid - 1;
				}
			}
			else
			{
				if (nums[mid] < target && target <= nums[r])
					l = mid + 1;

				else
					r = mid - 1;
			}

		}
		return -1;
	}
};