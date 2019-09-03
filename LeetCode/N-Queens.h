#pragma once
#include"stdafx.h"

using namespace std;
//51. N-Queens
//https://leetcode.com/problems/n-queens/

class Solution
{
public:
	vector<vector<string>> solveNQueens(int n)
	{
		vector<vector<string>> res;
		vector<string> board(n, string(n, '.'));

		Helper(res, board, 0, n);
		return res;
	}
	
	void Helper(vector<vector<string>>&res, vector<string>&board,int CurColumn,int &n)
	{
		if (CurColumn == n) 
		{
			res.push_back(board);
			return;
		}

		for (int r = 0; r < n; ++r) 
		{
			if (Valid(board, r, CurColumn, n)) 
			{
				board[r][CurColumn] = 'Q';
				Helper(res, board, CurColumn + 1, n);
				board[r][CurColumn] = '.';
			}
		}
	}

	bool Valid(vector<string>&board, int row, int column, int &n)
	{
		int r, c;

		for (c = 0; c < column; ++c)
		{
			if (board[row][c] == 'Q')return false;
		}

		for (c = column - 1, r = row - 1; c > -1 && r > -1; --c, --r)
		{
			if (board[r][c] == 'Q')return false;
		}
		for (c = column - 1, r = row + 1; c > -1 && r < n; --c, ++r)
		{
			if (board[r][c] == 'Q')return false;
		}
		return true;
	}
};
