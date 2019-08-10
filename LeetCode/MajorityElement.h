#pragma once
#include"stdafx.h"

//169. Majority Element
//https://leetcode.com/problems/majority-element/

using namespace std;

class Solution
{
public:
	int majorityElement(vector<int>& nums)
	{
		unordered_map<int, int> counter;

		int size = nums.size();
		int majcount = size / 2;

		for (int i = 0; i < size; ++i) 
		{
			counter[nums[i]]++;
			if (counter[nums[i]] > majcount)
				return nums[i];
		}
	}
};