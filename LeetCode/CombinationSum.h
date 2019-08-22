#pragma once
#pragma once
#include"stdafx.h"

using namespace std;

//39. Combination Sum
//https://leetcode.com/problems/combination-sum/

class Solution
{
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> res;

		Helper(res, candidates, vector<int>(), 0, target, 0);

		return res;
	}

	void Helper(vector<vector<int>>& res, vector<int>& candidates, vector<int> cur, int cursum, int& target, int left)
	{
		if (cursum == target)
		{
			res.push_back(cur);
			return;
		}
		if (cursum > target)
			return;

		int Cursize = cur.size();
		cur.resize(Cursize + 1);

		int CandidateSize = candidates.size();

		for (int i = left; i < CandidateSize; ++i)
		{
			cur[Cursize] = candidates[i];
			Helper(res, candidates, cur, cursum + candidates[i], target, i);
		}
	}
};