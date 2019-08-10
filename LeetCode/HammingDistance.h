#pragma once
#include"stdafx.h"

using namespace std;

//461. Hamming Distance
//https://leetcode.com/problems/hamming-distance/

namespace p461
{
	class Solution
	{
	public:
		int hammingDistance(int x, int y)
		{
			int xor = x ^ y;
			int dig = 0;
			while (xor > 0)
			{
				dig += xor & 1;
				xor = xor >> 1;
			}
			return dig;
		}
	};
}