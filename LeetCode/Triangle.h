#pragma once
#include"stdafx.h"

using namespace std;

//120. Triangle
//https://leetcode.com/problems/triangle/

namespace p120
{
	class Solution
	{
	public:
		int minimumTotal(vector<vector<int>>& triangle)
		{
			int height = triangle.size();
			if (!height)return 0;

			//init dp memo to last layer elements;
			vector<int> dp(triangle.back());

			for (int i = height - 2; i >= 0; --i)
			{
				for (int j = 0; j < triangle[i].size(); ++j)
				{
					dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
				}
			}
			return dp[0];
		}
	};
}