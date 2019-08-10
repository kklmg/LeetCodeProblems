#pragma once
#include"stdafx.h"

using namespace std;

//7. Reverse Integer
//https://leetcode.com/problems/reverse-integer/

namespace p7
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