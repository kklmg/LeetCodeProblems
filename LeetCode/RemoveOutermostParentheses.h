#pragma once
#include"stdafx.h"

//1021. Remove Outermost Parentheses
//https://leetcode.com/problems/remove-outermost-parentheses/description/

//A valid parentheses string is either empty(""), "(" + A + ")", 
//or A + B, where A and B are valid parentheses strings,
//and +represents string concatenation.For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

//A valid parentheses string S is primitive if it is nonempty, 
//and there does not exist a way to split it into S = A + B,
//with A and B nonempty valid parentheses strings.

//Given a valid parentheses string S, 
//consider its primitive decomposition : S = P_1 + P_2 + ... + P_k,
//where P_i are primitive valid parentheses strings.

//Return S after removing the outermost parentheses of every primitive string 
//in the primitive decomposition of S.


using namespace std;

class Solution 
{
public:
	string removeOuterParentheses(string S)
	{
		string result;

		int length = S.size();

		int i = 0, j = 0;

		for (; i < length; ++i) 
		{
			if (S[0] == '(' && j++>0)
				result.push_back(S[i]);
			if (S[0] == ')'&& j-->1)
				result.push_back(S[i]);		
		}
		return result;
	}
};