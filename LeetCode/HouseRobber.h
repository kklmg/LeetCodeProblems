#pragma once
#include"stdafx.h"

using namespace std;

//198. House Robber
//https://leetcode.com/problems/house-robber/

namespace p198
{
	class Solution
	{
	public:
		int rob(vector<int>& nums)
		{
			int size = nums.size();

			vector<int>dp(size + 1, 0);

			dp[0] = nums[0];
			dp[1] = max(nums[0], nums[1]);

			int i = 2;
			for (; i < size; ++i)
			{
				dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
			}
			return dp[i];
		}
	};
}