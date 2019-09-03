#pragma once
#include"stdafx.h"

using namespace std;

//841. Keys and Rooms
//https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms)
	{
		vector<bool>Visited(rooms.size(), false);

		stack<int>stk;

		stk.push(0);

		while (!stk.empty())
		{
			int curroom = stk.top();
			Visited[curroom] = true;
			stk.pop();

			for (int i = 0; i < rooms[curroom].size(); ++i)
			{
				if (!Visited[rooms[curroom][i]])stk.push(rooms[curroom][i]);
			}
		}
		for (bool v : Visited)
		{
			if (!v)return false;
		}
		return true;
	}
};