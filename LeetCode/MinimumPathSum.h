#pragma once
#include"stdafx.h"

using namespace std;

//64. Minimum Path Sum
//https://leetcode.com/problems/minimum-path-sum/description/

//Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

//Note: You can only move either down or right at any point in time.

//	Example :

//	Input :
//	[
//		[1, 3, 1],
//		[1, 5, 1],
//		[4, 2, 1]
//	]
//	Output : 7
//
//	Explanation : Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.


namespace p64
{
	class Solution
	{
	public:
		int minPathSum(vector<vector<int>>& grid)
		{
			int row = grid.size();
			int column = grid[0].size();
			int i, j;

			std::vector<int>memo(column, grid[0][0]);

			for (i = 1; i < column; ++i)
			{
				memo[i] = memo[i - 1] + grid[0][i];
			}

			for (i = 1; i < row; ++i)
			{
				memo[0] += grid[i][0];

				for (j = 1; j < column; ++j)
				{
					memo[j] = min(memo[j], memo[j - 1]) + grid[i][j];
				}
			}
			return memo[column - 1];
		}
	};
}
