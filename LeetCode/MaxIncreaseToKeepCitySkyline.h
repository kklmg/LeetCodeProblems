#pragma once
#include"stdafx.h"

using namespace std;

//807. Max Increase to Keep City Skyline
//https://leetcode.com/problems/max-increase-to-keep-city-skyline/

namespace p807
{
	class Solution
	{
	public:
		int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
		{
			int sum = 0;
			int Row = grid.size();
			int column = grid[0].size();

			vector<int>maxRow(Row, 0), maxColumn(column, 0);

			int i, j;

			for (i = 0; i < Row; ++i)
				for (j = 0; j < column; j++)
				{
					maxRow[i] = max(maxRow[i], grid[i][j]);
					maxColumn[j] = max(maxColumn[j], grid[i][j]);
				}

			for (i = 0; i < Row; ++i)
				for (j = 0; j < column; j++)
				{
					sum += min(maxRow[i], maxColumn[j]) - grid[i][j];
				}
			return sum;

		}
	};
}
