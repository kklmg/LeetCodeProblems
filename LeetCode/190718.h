#pragma once
#include"stdafx.h"

using namespace std;

//300. Longest Increasing Subsequence
//https://leetcode.com/problems/longest-increasing-subsequence/

namespace problem300
{
	class Solution
	{
	public:
		int lengthOfLIS(vector<int>& nums)
		{
			int size = nums.size();
			if (!size) return 0;

			vector<int>dp(size, 1);

			int i, j;
			int result = 1;
			for (i = 1; i < size; ++i)
			{
				for (j = 0; j < i; ++j)
				{
					if (nums[i] > nums[j])
					{
						dp[i] = max(dp[i], 1 + dp[j]);
					}
				}
				result = max(result, dp[i]);
			}
			return dp[size - 1];
		}
	};

	class Solution2
	{
	public:
		int lengthOfLIS(vector<int>& nums)
		{
			int size = nums.size();
			if (!size) return 0;

			vector<int> ends({ nums[0] });

			int i;
			for (i = 1; i < size; ++i)
			{
				auto it = lower_bound(ends.begin(), ends.end(), nums[i]);
				if (it == ends.end())
					ends.push_back(nums[i]);
				else *it = nums[i];
			}
			return ends.size();
		}
	};
}

//35. Search Insert Position
//https://leetcode.com/problems/search-insert-position/

class Solution 
{
public:
	int searchInsert(vector<int>& nums, int target)
	{
		int r = nums.size()-1;
		int l = 0;
		int m;
		while (l<r)
		{
			m = (r-l) / 2+l;

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