#pragma once
#include"stdafx.h"

using namespace std;

//322. Coin Change
//https://leetcode.com/problems/coin-change/
namespace p322
{
	class Solution
	{
	public:
		int coinChange(vector<int>& coins, int amount)
		{
			vector<int> table(amount + 1, amount + 1);
			table[0] = 0;

			for (int i = 0; i < amount; ++i) 
			{
				for (int picked : coins)
				{
					if (picked <= table[i])
						table[i] = min(table[i - picked] + 1, table[i]);
				}
			}
			return table[amount] > amount ? -1 : table[amount];
		}
	};

	class Solution2
	{
	public:
		int coinChange(vector<int>& coins, int amount)
		{
			vector<int> table(amount + 1, amount + 1);
			table[0] = 0;

			int i;
			for (int picked : coins)
				for (i = picked; i <= amount; ++i)
				{
					table[i] = min(table[i - picked] + 1, table[i]);
				}
			return table[amount] > amount ? -1 : table[amount];
		}
	};

	void test() 
	{
		Solution2 s;
		vector<int> coins = { 1,2,5 };
		s.coinChange(coins,11);

		return;
	
	}
}

