/*
 * Problem019.h
 *
 * <<<Insert short description here>>>
 * 	
 * Author: Stanimir Stoykov
 * $Id: $
 *	
 * Copyright (c) 2004-2012 EGT Ltd.
 * All rights reserved
	
 * More information at: http://www.egt-bg.com
 */

#ifndef PROBLEM019_H_
#define PROBLEM019_H_

/*
 * You are given the following information, but you may prefer to do some research for yourself.

	1 Jan 1900 was a Monday.
	Thirty days has September,
	April, June and November.
	All the rest have thirty-one,
	Saving February alone,
	Which has twenty-eight, rain or shine.
	And on leap years, twenty-nine.
	A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
	How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
	Answer: 171
 */

namespace PROBLEM019 {
bool IsLeap( int year )
{
	if ( (year % 4 == 0 && year % 100 != 0) ||
		 (year % 400 == 0 && year % 100 == 0) )
		return true;

	return false;
}
}

void Problem019()
{
	using namespace PROBLEM019;
	//					   Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
	int daysInMonth[12] = { 31, 28,   31,  30,  31,  30,  31,  31,  30,  31,  30,  31 };

	unsigned sumDays = 0;
	unsigned sundaysOnFirst = 0;
	for (int year = 1900; year < 2001; year++)
	{
		for ( int month = 0; month < 12; month++ )
		{
			sumDays += daysInMonth[month];

			if ( month == 1 && IsLeap(year) )
				sumDays += 1;

			if ( (sumDays+1) % 7 == 0 )
				sundaysOnFirst++;
		}
	}

	//2 Sundays on first day of the month in year 1900...
	sundaysOnFirst -= 2;

	std::cout << sundaysOnFirst << std::endl;
}

#endif /* PROBLEM019_H_ */
