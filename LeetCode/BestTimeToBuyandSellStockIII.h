#pragma once
#include"stdafx.h"

using namespace std;

// 123. Best Time to Buy and Sell Stock III
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

namespace p123
{
	//error : huge memory usage
	class Solution
	{
	public:
		int maxProfit(vector<int>& prices)
		{
			int size = prices.size();

			vector<vector<int>> table(size, vector<int>(0, size));


			int profit = 0;

			int buy, sell;

			for (buy = 0; buy < size; ++buy)
			{
				for (sell = buy + 1; sell < size; ++sell)
				{
					table[buy][sell] = max(table[buy][sell - 1], prices[sell] - prices[buy]);
				}
			}

			for (buy = 0; buy < size; ++buy)
			{
				for (sell = buy + 1; sell < size; ++sell)
				{
					if (sell + 1 < size)
						profit = max(profit, table[buy][sell] + table[sell + 1][size - 1]);
				}
			}
			return profit;
		}
	};

	class Solution2
	{
	public:
		int maxProfit(vector<int>& prices)
		{
			int maxProfit1 = 0;
			int maxProfit2 = 0;

			int lowestBuyPrice1 = INT_MAX;
			int lowestBuyPrice2 = INT_MAX;

			for (int p : prices)
			{
				maxProfit2 = max(maxProfit2, p - lowestBuyPrice2);
				lowestBuyPrice2 = min(lowestBuyPrice2, p - maxProfit1);

				maxProfit1 = max(maxProfit1, p - lowestBuyPrice1);
				lowestBuyPrice1 = min(lowestBuyPrice1, p);
			}

			return maxProfit2;
		}
	};

}