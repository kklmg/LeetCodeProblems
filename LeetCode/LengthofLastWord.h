#pragma once
#include"stdafx.h"

using namespace std;

//58. Length of Last Word
//https://leetcode.com/problems/length-of-last-word/

namespace p58
{
	class Solution
	{
	public:
		int lengthOfLastWord(string s)
		{
			int size = s.size();
			int res = 0;

			int i = size - 1;

			while (s[i] != ' ' && i > -1)
			{
				i--;
			}

			while (i > -1)
			{
				if (s[i--] == ' ')
					break;
				++res;
			}
			return res;
		}
	};
}


