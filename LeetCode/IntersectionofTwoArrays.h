#pragma once
#include"stdafx.h"

using namespace std;

//349. Intersection of Two Arrays
//https://leetcode.com/problems/intersection-of-two-arrays/

namespace p349
{
	class Solution
	{
	public:
		vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
		{
			unordered_map<int, bool> Table;
			vector<int> res;

			for (auto i : nums1) 
			{
				Table[i] = true;
			}
			for (auto j : nums2)
			{
				if (Table[j])
				{
					res.push_back(j);
					Table[j] = false;
				}
			}
			return res;
		}
	};
}