#pragma once
#include"stdafx.h"

using namespace std;

//852. Peak Index in a Mountain Array
//https://leetcode.com/problems/peak-index-in-a-mountain-array/
namespace p852
{
	class Solution
	{
	public:
		int peakIndexInMountainArray(vector<int>& A)
		{
			int size = A.size();

			int l = 0, r = size - 1, mid = l;

			while (l < r)
			{
				mid = (r + l) / 2;

				if (A[mid + 1] > A[mid])
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
			}

			return l;
		}
	};
}