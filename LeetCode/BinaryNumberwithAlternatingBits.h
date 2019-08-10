#pragma once


//693. Binary Number with Alternating Bits
//https://leetcode.com/problems/binary-number-with-alternating-bits/

namespace p693
{
	class Solution
	{
	public:
		bool hasAlternatingBits(int n)
		{
			int b = n & 1;
			while ((n & 1) == b)
			{
				//1 - 0 = 1, 1 - 1 = 0
				b = 1 - b;
				n >>= 1;
			}
			return n == 0;
		}
	};
}