#pragma once
#include"stdafx.h"

using namespace std;

//187. Repeated DNA Sequences
//https://leetcode.com/problems/repeated-dna-sequences/description/

//All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

//Write a function to find all the 10 - letter - long sequences(substrings) that occur more than once in a DNA molecule.

//Example:
//Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
//Output : ["AAAAACCCCC", "CCCCCAAAAA"]

namespace p187
{
	class Solution
	{
	public:
		vector<string> findRepeatedDnaSequences(string s)
		{
			vector<string> result;

			std::unordered_map<string, int>counter;

			int length = s.length();

			for (int i = 10; i <= length; ++i)
			{
				counter[s.substr(i-10, 10)]++;		
			}
			
			for (auto iter = counter.begin(); iter != counter.end(); ++iter) 
			{
				if (iter->second > 1)
					result.push_back(iter->first);	
			}

			return result;
		}
	};
	void test() 
	{
		string str = "AAAAAAAAAAA";
		Solution s;

		vector<string> result=
		s.findRepeatedDnaSequences(str);

		return;
	}

}