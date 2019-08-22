#pragma once
#include"stdafx.h"

using namespace std;

//88. Merge Sorted Array
//https://leetcode.com/problems/merge-sorted-array/

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		int i = m - 1;
		int j = n - 1;
		int slot = nums1.size()-1;

		while (i >= 0 && j >= 0) 
		{
			if (nums1[i]>nums2[j])  
				nums1[slot--] = nums1[i--];
			else            
				nums1[slot--] = nums2[j--];
		}

		while (j >= 0)       
			nums1[slot--] = nums2[j--];
	}
};