#pragma once
#include"stdafx.h"

using namespace std;

//860. Lemonade Change
//https://leetcode.com/problems/lemonade-change/

namespace p860
{
	class Solution
	{
	public:
		bool lemonadeChange(vector<int>& bills)
		{
			int change;
			int five = 0, ten = 0;

			for (int bill : bills)
			{
				if (bill == 5)
					++five;
				else if (bill == 10)
				{
					++ten;
					--five;
				}
				else if (bill == 20)
				{
					if (ten)
					{
						--ten;
						--five;
					}
					else
					{
						five -= 3;
					}
				}

				if (five < 0)
					return false;
			}
			return true;
		}
	};
}