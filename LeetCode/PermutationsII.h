#pragma once
#include"stdafx.h"

using namespace std;

//47. Permutations II
//https://leetcode.com/problems/permutations-ii/

namespace p47
{
	class Solution
	{
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums)
		{
			vector<vector<int>> res;
			sort(nums.begin(), nums.end());

			track(res, nums, 0, nums.size());
			return res;
		}

		void track(vector<vector<int>> &res, vector<int> choice, int left, int size)
		{
			if (left == size - 1)
			{
				res.push_back(choice);
				return;
			}
			for (int cur = left; cur < size; cur++)
			{
				if (cur != left  && choice[cur] == choice[left])
					continue;
				swap(choice[left], choice[cur]);
				track(res, choice, left + 1, size);
			}
		}
	};
}