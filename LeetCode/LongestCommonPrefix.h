#pragma once
#include"stdafx.h"

using namespace std;

//14. Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/

namespace p14
{
	class Solution
	{
	public:
		string longestCommonPrefix(vector<string>& strs)
		{
			int size = strs.size();

			if (!size)
				return "";
			if (size == 1)
				return strs[0];

			int shortID = 0, shortsize = INT_MAX;
			string res;
			int i, j;

			for (i = 0; i < size; i++)
			{
				if (strs[i].size() < shortsize)
				{
					shortID = i;
					shortsize = strs[i].size();
				}
			}

			for (j = 0; j < shortsize; ++i)
			{
				for (i = 1; i < size; ++i)
				{
					if (strs[i][j] != strs[i - 1][j])
						return res;
				}
				res.push_back(strs[shortID][j]);
			}
			return res;
		}
	};
}