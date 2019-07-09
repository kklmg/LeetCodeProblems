#pragma once
#include"stdafx.h"

//202. Happy Number
//https://leetcode.com/problems/happy-number/

//Write an algorithm to determine if a number is "happy".

//A happy number is a number defined by the following process : 
//Starting with any positive integer, replace the number by the sum of the squares of its digits,
//and repeat the process until the number equals 1 (where it will stay),
//or it loops endlessly in a cycle which does not include 1. 
//Those numbers for which this process ends in 1 are happy numbers.

//Example:

//  Input: 19
//	Output : true
//	Explanation :
//	1 ^ 2 + 9 ^ 2 = 82
//	8 ^ 2 + 2 ^ 2 = 68
//	6 ^ 2 + 8 ^ 2 = 100
//	1 ^ 2 + 0 ^ 2 + 0 ^ 2 = 1

namespace problem202
{
	class Solution
	{
	public:
		bool isHappy(int n)
		{
			int slow = n, fast = n;

			do
			{
				slow = getsum(slow);
				fast = getsum(fast);
				fast = getsum(fast);

				if (fast == 1)
					return true;
			} while (slow != fast);

			return false;
		}

		int getsum(int num)
		{
			int sum = 0;
			while (num)
			{
				sum += pow(num % 10, 2);
				num = num / 10;
			}
			return sum;
		}

	};
	void test()
	{
		Solution s;
		bool t1 = s.isHappy(10); 
		bool t2 = s.isHappy(17);
		bool t3 = s.isHappy(24);

		return;
	}

}


//floyd cycle detection algorithm