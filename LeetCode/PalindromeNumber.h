#pragma once
#include"stdafx.h"

using namespace std;

//9. Palindrome Number
//https://leetcode.com/problems/palindrome-number/

namespace p9
{
	class Solution
	{
	public:
		bool isPalindrome(int x)
		{
			if (x < 0)
				return false;

			vector<int>vec;

			int l = 0, r = -1;

			while (x)
			{
				vec.push_back(x % 10);
				x /= 10;
				++r;
			}


			while (l < r)
			{
				if (vec[l++] != vec[r--])
					return false;
			}
			return true;
		}
	};
}
