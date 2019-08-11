#pragma once
#include"stdafx.h"

using namespace std;

//1025. Divisor Game
//https://leetcode.com/problems/divisor-game/

namespace p1025
{
	class Solution
	{
	public:
		bool divisorGame(int N)
		{
			vector<bool>dp(N + 1, false);

			int i, j;

			for (i = 2; i <= N; i++)
			{
				for (j = 1; j< i; j++)
				{
					if (i % j == 0 && !dp[i - j])
						dp[i] = true;
				}
			}
			return dp[N];
		}
	};
}