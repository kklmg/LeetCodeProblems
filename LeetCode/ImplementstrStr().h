#pragma once
#include"stdafx.h"

using namespace std;

class Solution
{
public:
	int strStr(string haystack, string needle)
	{
		int sn = needle.size();
		if (!sn)return 0;

		int sh = haystack.size();

		int i, j, k;
		for (i = 0; i <= sh-sn; ++i) 
		{
			if (haystack[i] == needle[0])
			{
				for (j = 1, k = i+1; j < sn; ++j)
				{
					if (haystack[k++] != needle[j++])
						break;
				}
				if (j == sn)return i;
			}
		
		}

		return -1;
	}
};