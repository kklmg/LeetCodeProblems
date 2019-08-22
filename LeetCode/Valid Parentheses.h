#pragma once
#include"stdafx.h"

using namespace std;

//20. Valid Parentheses
//https://leetcode.com/problems/valid-parentheses/

class Solution 
{
public:
	bool isValid(string s)
	{
		int size = s.size();
		if (!size)
			return true;

		stack<char> stk;

		for (char c : s) 
		{
			if (c == '(' || c == '{' || c == '[') stk.push(c);

			if (c == ')') 
			{
				if (!stk.empty() && stk.top() == '(')
					stk.pop();
				else return false;
			} 

			if (c == '}')
			{
				if (!stk.empty() && stk.top() == '{')
					stk.pop();
				else return false;
			}

			if (c == ']')
			{
				if (!stk.empty() && stk.top() == '[')
					stk.pop();
				else return false;
			}
		}

		return stk.empty();
	}
};