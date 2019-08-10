#pragma once
#include"stdafx.h"

using namespace std;

//11. Container With Most Water
//https://leetcode.com/problems/container-with-most-water/

namespace p11
{
	class Solution
	{
	public:
		int maxArea(vector<int>& height)
		{
			int l = 0, r = height.size() - 1, hmax = 0;

			while (l < r)
			{
				if (height[l] <= height[r])
				{
					hmax = max(height[l] * (r - l), hmax);
					++l;
				}
				else
				{
					hmax = max(height[r] * (r - l), hmax);
					--r;
				}
			}
			return hmax;
		}
	};
}