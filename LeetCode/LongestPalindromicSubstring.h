#pragma once
#include"stdafx.h"

using namespace std;

//5. Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/solution/

namespace p5
{
	class Solution
	{
	public:
		string longestPalindrome(string s)
		{
			int size = s.size();

			if (size < 2)
				return s;

			int begin = 0, end = 0;
			vector<vector<bool>>state(size, vector<bool>(size, true));

			for (int i = size - 1; i > -1; --i)
			{
				for (int j = i; j < size; ++j)
				{

					state[i][j] = s[i] == s[j] && (j - i < 3 || state[i + 1][j - 1]);

					//update if cur str length > max length
					if (state[i][j] && j - i + 1 > end)
					{
						begin = i;
						end = j - i + 1;
					}
				}
			}
			return s.substr(begin, end);
		}
	};
	void test()
	{
		Solution s;

		s.longestPalindrome("babad");
	}
}
