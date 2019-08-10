#pragma once
#include"stdafx.h"

using namespace std;

//63. Unique Paths II
//https://leetcode.com/problems/unique-paths-ii/description/

//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).

//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).

//Now consider if some obstacles are added to the grids.How many unique paths would there be ?



//An obstacle and empty space is marked as 1 and 0 respectively in the grid.

//Note : m and n will be at most 100.

//	Example 1 :
//	Input :
//	[
//		[0, 0, 0],
//		[0, 1, 0],
//		[0, 0, 0]
//	]
//	Output : 2

//	Explanation :
//	There is one obstacle in the middle of the 3x3 grid above.
//	There are two ways to reach the bottom - right corner :
//		 1. Right->Right->Down->Down
//		 2. Down->Down->Right->Right


namespace p63
{
	class Solution
	{
	public:
		int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
		{
			int row = obstacleGrid.size();
			int column = obstacleGrid[0].size();

			std::vector<unsigned int>memo(column, 0);

			int i, j;

			for (j = 0; j < column; ++j)
			{
				if (!obstacleGrid[0][j])
				{
					memo[j] = 1;
				}
				else break;
			}


			for (i = 1; i < row; ++i)
			{
				if (obstacleGrid[i][0])
					memo[0] = 0;
				for (j = 1; j < column; ++j)
				{
					if (obstacleGrid[i][j])
						memo[j] = 0;
					else
						memo[j] = memo[j] + memo[j - 1];
				}
			}
			return memo[column - 1];
		}
	};
}



