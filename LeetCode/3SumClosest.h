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
			int sum = 0;
			int size = nums.size();
			sort(nums.begin(), nums.end());

			int l = 0, r = nums.size();
			int mid;

			while (l < r)
			{
				mid = (l + r) / 2;

				if (target > nums[mid])
				{
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}

			sum += nums[mid];
			l = r = mid;

			for (int i = 2; i > 0; --i)
			{
				if (l - 1 < 0)
				{
					while (i)
					{
						sum += mid;
						--i;
					}
					return sum;
				}

				if (r + 1 >= size)
				{
					while (i)
					{
						sum += mid;
						--i;
					}
					return sum;
				}

				if (abs(nums[l - 1] - target) > abs(nums[r + 1] - target))
				{
					sum += nums[++r];
				}
				else
				{
					sum += nums[--l];
				}
			}
			return sum;
		}

	};
	void test()
	{
		vector<int>nums = { -1,1,-2,3,4,5,7,9 };
		Solution s;
		s.threeSumClosest(nums, 7);
	}
}