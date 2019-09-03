#pragma once
#include"stdafx.h"

using namespace std;

//34. Find First and Last Position of Element in Sorted Array
//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/


class Solution
{
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int>res = { -1,-1 };
		int size = nums.size();

		if (!size)	return res;

		int l = 0;
		int r = size - 1;
		int mid;

		while (l<r)
		{
			mid = l + (r - l) / 2;

			if (nums[mid] < target) l = mid + 1;
			else r = mid;
		}

		if (nums[l] != target)
			return res;

		res[0] = l;

		r = size - 1;

		while (l<r)
		{
			mid = l + (r - l) / 2 + 1;

			if (target < nums[mid]) r = mid - 1;
			else l = mid;
		}

		res[1] = r;
		return res;
	}
};