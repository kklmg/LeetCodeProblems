#pragma once
#include"stdafx.h"

using namespace std;

//167. Two Sum II - Input array is sorted
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

namespace p167
{
	class Solution
	{
	public:
		vector<int> twoSum(vector<int>& numbers, int target)
		{
			int l = 0;
			int r = numbers.size() - 1;
			int sum;

			while (l < r)
			{
				sum = numbers[l] + numbers[r];

				if (sum == target)
				{
					return{ l + 1,r + 1 };
				}

				if (sum > target)
					--r;
				else
					++l;
			}

			return{};
		}
	};
}