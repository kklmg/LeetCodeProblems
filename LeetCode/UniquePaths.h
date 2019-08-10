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

namespace p62 
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


