#pragma once
#include"stdafx.h"

using namespace std;

//729. My Calendar I
//https://leetcode.com/problems/my-calendar-i/


//Implement a MyCalendar class to store your events. 
//A new event can be added if adding the event will not cause a double booking.

//Your class will have the method, book(int start, int end).Formally, this represents a booking on the half open interval[start, end), the range of real numbers x such that start <= x < end.

//A double booking happens when two events have some non - empty intersection
//(ie., there is some time that is common to both events.)

//For each call to the method MyCalendar.book, 
//return true if the event can be added to the calendar successfully without causing a double booking.
//Otherwise, return false and do not add the event to the calendar.

//Your class will be called like this : MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

//Example 1:
//MyCalendar();
//MyCalendar.book(10, 20); // returns true
//MyCalendar.book(15, 25); // returns false
//MyCalendar.book(20, 30); // returns true
//Explanation:
//The first event can be booked.The second can't because time 15 is already booked by another event.
//The third event can be booked, as the first event takes every time less than 20, but not including 20.
//
//
//Note :
//
//The number of calls to MyCalendar.book per test case will be at most 1000.
//In calls to MyCalendar.book(start, end), start and end are integers in the range[0, 10 ^ 9].

namespace p729
{
	class MyCalendar
	{
	public:
		MyCalendar()
		{

		}

		bool book(int start, int end)
		{
			auto up = m_map.upper_bound(start);

			if (up != m_map.end() && up->second < end)
			{
				return false;
			}

			m_map.insert(pair<int, int>(end, start));
			return true;
		}

		map<int, int> m_map;
	};

	/**
	* Your MyCalendar object will be instantiated and called as such:
	* MyCalendar* obj = new MyCalendar();
	* bool param_1 = obj->book(start,end);
	*/

	void test()
	{
		MyCalendar calender;

		calender.book(10,20);
		calender.book(15, 25);
		calender.book(20, 30);
		calender.book(30, 40);
		calender.book(35, 41);

		return;
	}

}