#pragma once

#include"stdafx.h"

using namespace std;


//844. Backspace String Compare
//https://leetcode.com/problems/backspace-string-compare/

namespace problem844
{
	class Solution
	{
	public:
		bool backspaceCompare(string S, string T) 
		{
			int curS = S.size() - 1;
			int curT = T.size() - 1;

			bool bs = true, bt = true;

			while (bs && bt)
			{
				bs = prev(S, curS);
				bt = prev(T, curT);

				if (bs && bt)
				{
					if (S[curS] == T[curT]) 
					{
						--curS;
						--curT;
					} 
					else return false;
				}
			}

			if (curS != curT)return false;
			else return true;
		}

		bool prev(string &str, int &curid)
		{
			int BScount = 0;

			while (curid > -1)
			{
				if (str[curid] == '#')
				{
					--curid;
					++BScount;
				}

				else if (BScount > 0)
				{
					--curid;
					--BScount;
				}
				else return true;
			}
			return false;
		}
	};

	class Solution2 
	{
		public:
			bool backspaceCompare(string S, string T)
			{
				stack<char>A;
				stack<char>B;

				addStack(A, S);
				addStack(B, T);

				if (A.size() != B.size())
					return false;

				while (!A.empty() && !B.empty())
				{
					if (A.top() == B.top()) 
					{
						A.pop();
						B.pop();
					}
					else return false;
				}
				return true;


			}
			void addStack(stack<char>&stack,string &str)
			{
				for (auto c : str) 
				{
					if (c == '#') 
					{
						if(!stack.empty())
							stack.pop();
					}					
					else
						stack.push(c);
				}
			}
	
	};

	void test() 
	{
		Solution2 s;
		//string S("bxj##tw");
		//string T("bxj###tw");
		//string S("ab##");
		//string T("c#d#");
		string S("y#fo##f");
		string T("y#f#o##f");

		bool result = s.backspaceCompare(S, T);
		return;
	}



}



//501. Find Mode in Binary Search Tree
//https://leetcode.com/problems/find-mode-in-binary-search-tree/
namespace problem501
{
	class Solution
	{
	public:
		vector<int> findMode(TreeNode* root)
		{
			unordered_map<int, int>counter;
			vector<int>result;

			int max = getmax(root, counter);

			for (auto iter : counter)
			{
				if (max == iter.second)
					result.push_back(iter.first);
			}
			return result;

		}
		int getmax(TreeNode* root, unordered_map<int, int>&_map)
		{
			if (!root)
				return 0;

			_map[root->val]++;

			return max(_map[root->val],
				max(getmax(root->left, _map), getmax(root->right, _map)));
		}

	};
}