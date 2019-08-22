#pragma once
#include"stdafx.h"

using namespace std;

//90. Subsets II
//https://leetcode.com/problems/subsets-ii/

class Solution
{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums)
	{
		vector<vector<int>> res(1);
		sort(nums.begin(), nums.end());

		Helper(res, nums, vector<int>(), 0);
		return res;
	}
	void Helper(vector<vector<int>>&res, vector<int>& nums, vector<int>cur, int left)
	{

		for (int j = left; j < nums.size(); ++j)
		{
			if (j > left && nums[j] == nums[j - 1]) continue;

			cur.push_back(nums[j]);
			res.push_back(cur);

			Helper(res, nums, cur, j + 1);
			cur.pop_back();
		}
	}
};