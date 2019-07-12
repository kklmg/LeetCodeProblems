#pragma once
#include"stdafx.h"

using namespace std;


//1014. Best Sightseeing Pair
//https://leetcode.com/problems/best-sightseeing-pair/

//Given an array A of positive integers, A[i] represents the value of the i - th sightseeing spot, 
//and two sightseeing spots i and j have distance j - i between them.

//The score of a pair(i < j) of sightseeing spots is(A[i] + A[j] + i - j) : 
//	the sum of the values of the sightseeing spots, minus the distance between them.

//Return the maximum score of a pair of sightseeing spots.



//Example 1:

//	Input: [8, 1, 5, 2, 6]
//	Output : 11
//	Explanation : i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11


//	Note :
//	2 <= A.length <= 50000
//	1 <= A[i] <= 1000


namespace problem1014
{
	class Solution
	{
	public:
		int maxScoreSightseeingPair(vector<int>& A)
		{
			int result = ComputeScore(0, 1, A);
			int size = A.size();
			int i, j;

			for (i = 0; i < size; ++i)
			{
				for (j = i+1; j < size; ++j) 
				{
					result = max(ComputeScore(i, j, A), result);
				}
			}
			return result;
		}

		int ComputeScore(int a,int b,vector<int>& vec)
		{
			return vec[a] + vec[b] + a - b;	
		}
	};

	class Solution2 
	{
	public:
		int maxScoreSightseeingPair(vector<int>& A)
		{
			int left = A[0] + 0;

			int Score = INT_MIN;
			
			for (int j = 1; j < A.size(); ++j) 
			{
				Score = max(left + A[j] - j, Score);

				left = max(left, A[j] + j);
			}
			return Score;
		}
	};


	void test() 
	{
		vector<int>A = {8,1,5,2,6};
		Solution2 s;
		int score =
		s.maxScoreSightseeingPair(A);
		return;
	}



}