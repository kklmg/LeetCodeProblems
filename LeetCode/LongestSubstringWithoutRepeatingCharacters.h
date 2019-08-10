#pragma once
#include"stdafx.h"

using namespace std;

//3.Longest Substring Without Repeating Characters
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

namespace p3
{
	class Solution
	{
	public:
		int lengthOfLongestSubstring(string s)
		{
			int size = s.size(), res = 0;
			unordered_map<char, int>table;

			int l = 0, r = 0;

			for (; r < size; ++r)
			{
				if (!table.insert(make_pair(s[r], r + 1)).second)
					l = max(table[s[r]], l);

				res = max(res, r - l + 1);
				table[s[r]] = r + 1;
			}
			return res;
		}		
	};

	void test() 
	{
		Solution s;
		string str = "dvdadcdbded";
		s.lengthOfLongestSubstring(str);
	}
}