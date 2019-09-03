#pragma once
#include"stdafx.h"

using namespace std;

//191. Number of 1 Bits
//https://leetcode.com/problems/number-of-1-bits/

class Solution
{
public:
	int hammingWeight(uint32_t n)
	{
		int res = 0;
		while (n)
		{
			if (n & 1) ++res;			
			n = n >> 1;
		}
		return res;
	}
};