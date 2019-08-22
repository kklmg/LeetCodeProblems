#pragma once
#include"stdafx.h"

using namespace std;

//17. Letter Combinations of a Phone Number

namespace p17
{
	class Solution
	{
		string mapping[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	public:
		vector<string> letterCombinations(string digits)
		{
			int size = digits.size();
			if (!size)return  vector<string>();

			vector<string> res;

			helper(0, "", res, digits);

			return res;
		}

		void helper(int curid, string curstr, vector<string>& res, string &digits)
		{
			if (curid == digits.size()) 
			{
				res.push_back(curstr);
			}

			else
			{
				int mapped = digits[curid] - 2;
				int count = mapping[mapped].size();

				for (int i = 0; i <count; ++i)
				{
					helper(curid + 1, curstr + mapping[mapped][i], res, digits);
				}
			}
		}
	};
	void test() 
	{
		Solution s;
		auto res =
		s.letterCombinations("23");

		return;
	}
}