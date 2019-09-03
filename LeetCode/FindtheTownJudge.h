#pragma once
#include"stdafx.h"

using namespace std;


//997. Find the Town Judge
//https://leetcode.com/problems/find-the-town-judge/

class Solution
{
public:
	int findJudge(int N, vector<vector<int>>& trust)
	{
		vector<int> _trust(N + 1, 0);
		vector<int> _trusted(N + 1, 0);

		for (auto& t : trust) 
		{
			++_trust[t[0]];
			++_trusted[t[1]];
		}

		for (int i = 0; i < N + 1; ++i)
		{
			if (_trust[i] == 0 && _trusted[i] == N - 1)
				return i;

		}
		return -1;
	}
};