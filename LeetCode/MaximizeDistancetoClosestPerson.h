#pragma once
#include"stdafx.h"

using namespace std;

//849. Maximize Distance to Closest Person
//https://leetcode.com/problems/maximize-distance-to-closest-person/

namespace p849
{
	class Solution
	{
	public:
		int maxDistToClosest(vector<int>& seats)
		{
			int size = seats.size();
			int CurMax = 0;
			int l = -1;

			for (int i = 0; i < size; ++i) 		
			{
				if (seats[i]) 
				{
					CurMax = l < 0 ? i : max(CurMax, (i - l) / 2);

					l = i;
				}
			}

			return  max(CurMax , size - l - 1);		
		}
	};
}