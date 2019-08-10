#pragma once
#include"stdafx.h"

using namespace std;

//718. Maximum Length of Repeated Subarray
//https://leetcode.com/problems/maximum-length-of-repeated-subarray/

namespace p718
{
	class Solution
	{
	public:
		int findLength(vector<int>& A, vector<int>& B)
		{
			int sa = A.size() + 1;
			int sb = B.size() + 1;

			vector<vector<int>>dp(sa, vector<int>(sb, 0));

			int res = 0;

			int i, j;
			for (i = 1; i < sa; ++i)
			{
				for (j = 1; j < sb; ++j)
				{
					if (A[i - 1] == B[j - 1])
					{
						dp[i][j] = dp[i - 1][j - 1] + 1;
						res = max(res, dp[i][j]);
					}
				}
			}
			return res;
		}
	};
}