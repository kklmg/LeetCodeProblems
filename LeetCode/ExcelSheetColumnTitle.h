#pragma once
#include"stdafx.h"

using namespace std;

//168. Excel Sheet Column Title
//https://leetcode.com/problems/excel-sheet-column-title/

namespace p168
{
	class Solution
	{
	public:
		string convertToTitle(int n)
		{
			string res;

			while (n)
			{
				res.push_back((n - 1) % 26 + 'A');
				n = (n - 1) / 26;
			}

			reverse(res.begin(), res.end());

			return res;
		}
	};
}