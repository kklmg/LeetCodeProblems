#pragma once
#include"stdafx.h"

using namespace std;

//389. Find the Difference
//https://leetcode.com/problems/find-the-difference/
namespace p389
{
	class Solution
	{
	public:
		char findTheDifference(string s, string t)
		{
			char res = 0;
			for (auto i : s)
				res ^= i;
			for (auto i : t)
				res ^= i;

			return res;
		}
	};
}