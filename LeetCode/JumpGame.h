#pragma once
#include"stdafx.h"

using namespace std;

//55. Jump Game
//https://leetcode.com/problems/jump-game/

class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		for (int i = 1, step = nums[0]; i<nums.size(); ++i) 
		{
			--step;

			if (step < 0)
				return false;
			if (nums[i] > step)
				step = nums[i];
		}
		return true;

	}
};