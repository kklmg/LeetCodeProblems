#pragma once
#include"stdafx.h"

using namespace std;

//977. Squares of a Sorted Array
//https://leetcode.com/problems/squares-of-a-sorted-array/

namespace p977
{
	class Solution
	{
	public:
		vector<int> sortedSquares(vector<int>& A)
		{
			int l = 0, r = A.size() - 1;
			int i = r;
			vector<int> res(r);

			while (l < r)
			{
				if (abs(A[l]) > abs(A[r]))
				{
					res[i--] = A[l] * A[l];
					++l;
				}
				else
				{
					res[i--] = A[r] * A[r];
					--r;
				}
			}
			return res;
		}
	};
}