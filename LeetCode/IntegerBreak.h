#pragma once
#include"stdafx.h"

using namespace std;

//343. Integer Break
//https://leetcode.com/problems/integer-break/

namespace p343
{
	class Solution
	{
	public:
		int integerBreak(int n)
		{
			vector<int>table(n + 1, 0);
			int res;

			for (int i = 0; i < n; ++i)
			{
				table[i] = i - 1;
				for (int j = 0; j < i; ++j)
				{
					table[i] = max(table[i], j * (i - j));
				}

				res = max(res, table[i]);
			}

			return res;
		}
	};
}