#pragma once
#include"stdafx.h"

using namespace std;

//209. Minimum Size Subarray Sum
//https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		int size = nums.size();
		int l = 0, r = 0;

		int sum = 0;
		int res = INT_MAX;

		while (r < size)
		{
			sum += nums[r];
			++r;

			while (sum >= s)
			{
				res = min(res, r - l);
				sum -= nums[l];
				++l;
			}
		}

		return res != INT_MAX ? res : 0;
	}
};