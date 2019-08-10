#pragma once
#include"stdafx.h"

using namespace std;

//4. Median of Two Sorted Arrays
//https://leetcode.com/problems/median-of-two-sorted-arrays/

namespace p4
{
	class Solution
	{
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
		{
			int sn1 = nums1.size();
			int sn2 = nums2.size();

			if (sn1 > sn2)
			{
				return findMedianSortedArrays(nums2, nums1);
			}

			int l = 0, r = sn1;
			int pi, pj;

			while (l <= r)
			{
				pi = (l + r) >> 1;

				//pi + pj = (sn1 + sn2) / 2;
				pj = ((sn1 + sn2 + 1) >> 1) - pi;


				if (pi && nums1[pi - 1] > nums2[pj])
				{
					r = pi - 1;
				}
				else if (pi < sn1 && nums2[pj - 1] > nums1[pi])
				{
					l = pi + 1;
				}
				else
				{
					int lmax;

					//if partion index i != 0
					if (pi)
					{
						//if partition index j != 0
						if (pj)
							lmax = max(nums1[pi - 1], nums2[pj - 1]);
						else
							lmax = nums1[pi - 1];
					}
					else
						lmax = nums2[pj - 1];

					if ((sn1 + sn2) % 2)
						return lmax;

					int rmin;

					if (pi != sn1)
					{
						if (pj == sn2)
							rmin = nums1[pi];
						else
							rmin = min(nums1[pi], nums2[pj]);
					}
					else
						rmin = nums2[pj];

					return (lmax + rmin) >> 1;
				}
			}
			return 0.0;
		}
	};
	void test() 
	{
		vector<int> A = { 1,3,5,7,9 };
		vector<int>B = { 0 };
		Solution s;
		double result=
		s.findMedianSortedArrays(A,B);
		int a = 1;
	}
};
