#pragma once
#include"stdafx.h"

using namespace std;

//62. Unique Paths
//https://leetcode.com/problems/unique-paths/description/

//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//The robot can only move either down or right at any point in time.
//The robot is trying to reach the bottom 
//	- right corner of the grid(marked 'Finish' in the diagram below).
//How many possible unique paths are there ?


//Note: m and n will be at most 100.
//
//	Example 1 :
//	Input : m = 3, n = 2
//	Output : 3
//
//	Explanation :
//	From the top - left corner, 
//	there are a total of 3 ways to reach the bottom - right corner :
//	  1. Right->Right->Down
//	  2. Right->Down->Right
//	  3. Down->Right->Right
//
//	Example 2 :
//
//	Input : m = 7, n = 3
//	Output : 28

namespace problem62 
{
	class Solution
	{
	public:
		int uniquePaths(int m, int n)
		{
			if (m == 0 && n == 0)
				return 1;
			else if (m == 0)
				return uniquePaths(m, n-1);
			else if(n==0)
				return uniquePaths(m-1, n);
			else
				return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		}
	};

	class Solution2
	{
	public:
		int uniquePaths(int m, int n)
		{
			std::vector<int>memo(n, 1);

			int i,j;
		
			for (i = 1; i < m; ++i) 
			{
				for (j = 1; j < n; ++j) 
				{
					memo[j] = memo[j] + memo[j - 1];
				}
			}
			return memo[n - 1];
		}
	};

	void test() 
	{
		Solution s1;
		Solution2 s2;

		int a, b;
		a = s1.uniquePaths(13, 14);

		b = s2.uniquePaths(13, 14);

		return;
	}
}


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


namespace problem63
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


namespace problem64
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


