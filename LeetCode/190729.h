#pragma once
#include"stdafx.h"

using namespace std;


//5. Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/solution/

namespace problem5
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

//7. Reverse Integer
//https://leetcode.com/problems/reverse-integer/

namespace problem7
{
	class Solution
	{
	public:
		int reverse(int x)
		{
			long res = 0;

			while (x)
			{
				res = res * 10 + x % 10;
				x = x / 10;
				if (res > INT_MAX || res < INT_MIN)
					return 0;
			}
			return (int)res;
		}
		
	};
}

//8. String to Integer (atoi)
//https://leetcode.com/problems/string-to-integer-atoi/

namespace problem8
{
	class Solution
	{
	public:
		int myAtoi(string str)
		{
			int size = str.size();
			if (!size) return 0;

			int res = 0;
			int i = str[0] == '-' ? 1 : 0;

			for (; i < size; ++i)
			{
				res = res * 10 + str[i] - '0';
			}

			return str[0] == '-' ? -res : res;
		}
	};
}