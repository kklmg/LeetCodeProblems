#pragma once
#include"stdafx.h"

using namespace std;

//788. Rotated Digits
//https://leetcode.com/problems/rotated-digits/

namespace p788
{
	class Solution
	{
	public:
		int rotatedDigits(int N)
		{	
			int Count = 0;

			for (int i = 1; i <= N; i++)
			{
				if (isGood(i))
					++Count;
			}
			return Count;
		}

		bool isGood(int n)
		{
			bool bGood = false;
			int digit;

			while (n)
			{
				digit = n % 10;

				switch (digit)
				{
				case 3:
				case 4:
				case 7: return false;
					break;
				case 2:
				case 5:
				case 6:
				case 9: bGood = true;
					break;
				}
				n /= 10;  // Shift decimal digits right 1
			}

			return bGood;
		}
	};
}


