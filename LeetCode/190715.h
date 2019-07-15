#pragma once
#include"stdafx.h"
using namespace std;

//480. Sliding Window Median
//https://leetcode.com/problems/sliding-window-median/

namespace problem409
{
	class Solution
	{
	public:
		vector<double> medianSlidingWindow(vector<int>& nums, int k)
		{
			int size = nums.size();

			if (size == 1)return vector<double>(1, nums[0]);

			bool odd = k % 2;

			vector<double>result;
			result.reserve(size - 2);
			multiset<int> window(nums.begin(), nums.begin() + k);

			multiset<int>::iterator itermid = next(window.begin(), k / 2);

			for (int i = k; ; ++i)
			{
				if (odd)
					result.push_back(*itermid);
				else
					result.push_back((double(*itermid) + *prev(itermid, 1)) / 2);

				if (i == size)
					return result;

				window.insert(nums[i]);

				if (nums[i] < *itermid)
					--itermid;
				if (nums[i - k] <= *itermid)
					++itermid;

				window.erase(window.lower_bound(nums[i - k]));
			}
		}
	};

	void test()
	{
		vector<int> vec = { 4,5,6,7,1 };

		Solution s;
		vector<double>result =
			s.medianSlidingWindow(vec,2);
		return;
	}

}