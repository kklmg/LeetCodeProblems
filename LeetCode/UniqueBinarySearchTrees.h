#pragma once
#include"stdafx.h"

using namespace std;

//96. Unique Binary Search Trees
//https://leetcode.com/problems/unique-binary-search-trees/

class Solution
{
public:
	int numTrees(int n)
	{
		vector<int>dp;

		dp[0] = 1;
		int i, j;
		for (i = 1; i < n; ++i)
		{
			for (j = i - 1; j > 0; j--)
			{
				dp[i] = dp[i];
			}
		}
		return dp[i];


	}
};