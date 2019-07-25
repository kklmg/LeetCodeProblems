#pragma once
#include"stdafx.h"

using namespace std;

//718. Maximum Length of Repeated Subarray
//https://leetcode.com/problems/maximum-length-of-repeated-subarray/

namespace problem718 
{
	class Solution
	{
	public:
		int findLength(vector<int>& A, vector<int>& B)
		{
			int sa = A.size() + 1;
			int sb = B.size() + 1;

			vector<vector<int>>dp(sa, vector<int>(sb, 0));

			int res = 0;

			int i, j;
			for (i = 1; i < sa; ++i)
			{
				for (j = 1; j < sb; ++j)
				{
					if (A[i - 1] == B[j - 1])
					{
						dp[i][j] = dp[i - 1][j - 1] + 1;
						res = max(res, dp[i][j]);
					}
				}
			}
			return res;
		}
	};

}

//209. Minimum Size Subarray Sum
//https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution
{
public:
	int minSubArrayLen(int s, vector<int>& nums)
	{
		binary_search(nums.begin(), nums.end(),0);
		int size = nums.size();
		int l = 0, r = 0;

		int sum = 0;
		int res = INT_MAX;

		while (r < size)
		{
			sum += nums[r];
			++r;

			while (sum >= s)
			{
				res = min(res, r - l);
				sum -= nums[l];
				++l;
			}
		}

		return res != INT_MAX ? res : 0;
	}
};

//977. Squares of a Sorted Array
//https://leetcode.com/problems/squares-of-a-sorted-array/
namespace problem977
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