#pragma once
#include"stdafx.h"

using namespace std;


//32. Longest Valid Parentheses
//https://leetcode.com/problems/longest-valid-parentheses/

namespace p32
{
	class Solution
	{
	public:
		int longestValidParentheses(string s)
		{
			int res = 0;
			int size = s.size();

			if (size < 2)
				return 0;

			vector<int> dp(size + 1, 0);
			
			int i;
			for (i = 1; i < size; ++i) 
			{
				if (s[i] == ')') 
				{
					if (s[i - 1] == '(') 
					{
						dp[i] = (i - 2) >= 0 ? (dp[i - 2] + 2) : 2;

						res = max(dp[i], res);
					}
					
					else //if s[i-1] == ')'
					{ 
						if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')
						{
							dp[i] = dp[i - 1] + 2 + ((i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0);
							res = max(dp[i], res);
						}
					}
				}
			}
			return res;
		}
	};

	class Solution2
	{
	public:
		int longestValidParentheses(string s)
		{
			int res = 0;
			int size = s.size();

			stack<int> stk;

			stk.push(-1);

			int i, top;
			for (i = 1; i <size; ++i)
			{
				top = stk.top();

				if (top != -1 && s[top] == '(' && s[i] == ')')
				{
					stk.pop();

					res = max(res, i - top);
				}
				else
					stk.push(i);
			}
			return res;
		}
	};
}