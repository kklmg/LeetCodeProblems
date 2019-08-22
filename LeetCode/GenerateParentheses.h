#pragma once
#include"stdafx.h"

using namespace std;

class Solution
{
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> res;

		Helper("", res, n, n);
		
		return res;
	}

	void Helper(string curstr, vector<string>& vec,int open, int close)
	{
		if (open == 0 && close == 0) 
		{
			vec.push_back(curstr);
			return;
		}
		if (open > close) 
			return;
		if (open < 0 || close < 0)
			return;

		Helper(curstr + '(', vec, open - 1, close);
		Helper(curstr + ')', vec, open, close-1);
	}
};