#pragma once
#include"stdafx.h"


using namespace std;

//120. Triangle
//https://leetcode.com/problems/triangle/

namespace problem120
{
	class Solution
	{
	public:
		int minimumTotal(vector<vector<int>>& triangle)
		{		
			int height = triangle.size();
			if (!height)return 0;

			//init dp memo to last layer elements;
			vector<int> dp(triangle.back());

			for (int i = height-2; i >= 0; --i) 
			{
				for (int j = 0; j < triangle[i].size(); ++j) 
				{
					dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];				
				}	
			}
			return dp[0];
		}
	};
}


//47. Permutations II
//https://leetcode.com/problems/permutations-ii/

namespace problem47
{
	class Solution
	{
	public:
		vector<vector<int>> permuteUnique(vector<int>& nums)
		{
			vector<vector<int>> res;
			sort(nums.begin(), nums.end());

			track(res, nums, 0, nums.size());
			return res;
		}

		void track(vector<vector<int>> &res, vector<int> choice, int left, int size)
		{
			if (left == size - 1)
			{
				res.push_back(choice);
				return;
			}
			for (int cur = left; cur < size; cur++)
			{
				if (cur != left  && choice[cur] == choice[left])
					continue;
				swap(choice[left], choice[cur]);
				track(res, choice, left + 1, size);
			}
		}
	};
}

//58. Length of Last Word
//https://leetcode.com/problems/length-of-last-word/
namespace problem58
{
	class Solution
	{
	public:
		int lengthOfLastWord(string s)
		{
			int size = s.size();
			int res = 0;

			int i = size - 1;

			while (s[i] != ' ' && i > -1)
			{
				i--;
			}

			while (i > -1)
			{
				if (s[i--] == ' ')
					break;
				++res;
			}
			return res;
		}
	};
}


