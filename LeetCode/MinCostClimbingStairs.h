#pragma once
#include"stdafx.h"

using namespace std;

//746. Min Cost Climbing Stairs
//https://leetcode.com/problems/min-cost-climbing-stairs/

namespace p746
{
	class Solution
	{
	public:
		int minCostClimbingStairs(vector<int>& cost)
		{
			int size = cost.size();

			vector<int>dp(size, 0);

			dp[0] = cost[0];
			dp[1] = cost[1];

			int i = 2;
			for (; i < size; ++i)
			{
				dp[i] = cost[i] + min(dp[i - 2], dp[i - 1]);
			}
			return min(dp[size - 2], dp[size - 1]);
		}
	};
}