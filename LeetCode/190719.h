#pragma once

#include"stdafx.h"

using namespace std;

//572. Subtree of Another Tree
//https://leetcode.com/problems/subtree-of-another-tree/

namespace problem572
{
	class Solution
	{
	public:
		bool isSubtree(TreeNode* s, TreeNode* t)
		{
			if (!s) return false;

			if (isSame(s, t))
				return true;

			return
				(isSubtree(s->left, t) || isSubtree(s->right, t));
		}

		bool isSame(TreeNode* s, TreeNode* t)
		{
			if (!s && !t)
				return true;

			if (!s || !t)
				return false;

			if (s->val != t->val)
				return false;

			return isSame(s->left, t->left) && isSame(s->right, t->right);
		}
	};
}


//3. Longest Substring Without Repeating Characters
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

namespace problem3
{
	class Solution
	{
	public:
		int lengthOfLongestSubstring(string s)
		{
			int size = s.size(), res = 0;
			unordered_map<char, int>table;

			int l = 0, r = 0;

			for (; r < size; ++r)
			{
				if (!table.insert(make_pair(s[r], r + 1)).second)
					l = max(table[s[r]], l);

				res = max(res, r - l + 1);
				table[s[r]] = r + 1;
			}
			return res;
		}		
	};

	void test() 
	{
		Solution s;
		string str = "dvdadcdbded";
		s.lengthOfLongestSubstring(str);
	}
}