#pragma once
#include"stdafx.h"

using namespace std;

//16. 3Sum Closest
//https://leetcode.com/problems/3sum-closest/

namespace p16
{
	class Solution
	{
	public:

		int threeSumClosest(vector<int>& nums, int target)
		{
			int size = nums.size();

			if (size < 3)
				return 0;

			int ClosestSum = nums[0] + nums[1] + nums[2];

			sort(nums.begin(), nums.end());

			int first = 0, second, third;
			int CurSum;


			for (; first < size; ++first)
			{
				if (first > 0 && nums[first] == nums[first - 1]) continue;

				second = first + 1;
				third = size - 1;
				
				while (second<third)
				{

					CurSum = nums[first] + nums[second] + nums[third];
				
					if (CurSum == target)
						return CurSum;

					if (abs(target - ClosestSum) > abs(target - CurSum))
						ClosestSum = CurSum;
					
					if (CurSum > target)
						--third;
					else
						++second;
				}
			}

			return ClosestSum;
		}

	};
	void test()
	{
		vector<int>nums = { -1,1,-2,3,4,5,7,9 };
		Solution s;
		s.threeSumClosest(nums, 7);
	}
}