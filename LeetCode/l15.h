#pragma once
#include"stdafx.h"

using namespace std;

//15. 3Sum
//https://leetcode.com/problems/3sum/

//Given an array nums of n integers, are there elements a, b, c in nums
//such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.

//Note :

//	The solution set must not contain duplicate triplets.

//	Example :

//	Given array nums = [-1, 0, 1, 2, -1, -4],

//	A solution set is :
//[
//	[-1, 0, 1],
//	[-1, -1, 2]
//]


namespace problem15
{
	class Solution
	{
	public:
		vector<vector<int>> threeSum(vector<int>& nums)
		{
			vector<vector<int>> result;
			vector<int> temp(3);

			sort(nums.begin(), nums.end());

			int size = nums.size();
			int target, sum, front, back;

			for (int i = 0; i < size; ++i)
			{
				target = -nums[i];
				front = i + 1;
				back = size - 1;

				while (front < back)
				{
					sum = nums[front] + nums[back];

					if (sum > target)
						--back;
					else if (sum < target)
						++front;
					else
					{
						temp[0] = nums[i];
						temp[1] = nums[front];
						temp[2] = nums[back];
						result.push_back(temp);

						while (front < back && nums[front] == temp[1])
							++front;
						while (front < back && nums[back] == temp[2])
							--back;
						while (i + 1 < size && nums[i + 1] == temp[0])
							++i;
					}
				}
			}
			return result;
		}
	};


	void test()
	{
		vector<int> a = { -1,0,1,2,-1,-4 };

		Solution s;

		vector<vector<int>> result = s.threeSum(a);

		return;
	}
}
