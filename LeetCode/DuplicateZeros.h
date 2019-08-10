#pragma once
#include"stdafx.h"

using namespace std;

//1089. Duplicate Zeros
//https://leetcode.com/problems/duplicate-zeros/

class Solution
{
public:
	void duplicateZeros(vector<int>& arr) 
	{
		int size = arr.size();

		vector<int> vec(size);
		int i = 0, j = 0;
		for (; i < size; ++i,++j) 
		{
			vec[i] = arr[j];

			if (arr[j] == 0)
			{
				if(i+1<size)
				vec[++i] = 0;	
			}
		}	
		arr = vec;
	}
};