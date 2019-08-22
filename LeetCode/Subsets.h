#pragma once
#include"stdafx.h"

using namespace std;

//78. Subsets
//https://leetcode.com/problems/subsets/

class Solution
{
public:
	vector<vector<int>> subsets(vector<int>& nums)
	{
		vector<vector<int>> res(1);
		Helper(res, nums, vector<int>(), 0);
		return res;
	}

	void Helper(vector<vector<int>>&res, vector<int>& nums, vector<int>cur, int left)
	{

		for (int j = left; j < nums.size(); ++j)
		{
			cur.push_back(nums[j]);
			res.push_back(cur);
			Helper(res, nums, cur, j + 1);
			cur.pop_back();
		}
	}
};