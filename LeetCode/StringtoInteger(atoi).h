#pragma once
#include"stdafx.h"

using namespace std;

//8. String to Integer (atoi)
//https://leetcode.com/problems/string-to-integer-atoi/

namespace p8
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