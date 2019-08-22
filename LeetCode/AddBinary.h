#pragma once
#include"stdafx.h"

using namespace std;

//67. Add Binary
//https://leetcode.com/problems/add-binary/

class Solution
{
public:
	string addBinary(string a, string b)
	{
		string res;
		int i = a.size() - 1;
		int j = b.size() - 1;
		int carry = 0;

		while (i >-1 || j >-1 || carry == 1)
		{
			carry += i >-1 ? a[i--] - '0' : 0;
			carry += j >-1 ? b[j--] - '0' : 0;

			res = char(carry % 2 + '0') + s;
			carry /= 2;
		}

		return res;
		
	}
};