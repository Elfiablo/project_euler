/*
 * Problem040.h
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

#ifndef PROBLEM040_H_
#define PROBLEM040_H_

/*
 * An irrational decimal fraction is created by concatenating the positive integers:

	0.123456789101112131415161718192021...

	It can be seen that the 12th digit of the fractional part is 1.

	If dn represents the nth digit of the fractional part, find the value of the following expression.

	d1 x d10 x d100 x d1000 x d10000 x d100000 x d1000000
	Answer: 210
 */
#include <sstream>
void Problem040()
{
	int step = 1;
	int i = 0;
	int digits = 0;
	int powerOfTen = 10;
	int values[7] = { 1, 10, 100, 1000, 10000, 100000, 1000000};
	int idx = 0;

	int sum = 1;
	do
	{
		i++;
		if ( !(i % powerOfTen) )
		{
			step++;
			powerOfTen *= 10;
		}
		digits += step;
		if ( digits >= values[idx] )
		{
			std::stringstream stream;
			stream << i;
			int offset = values[idx] - (digits - step);
			std::cout << stream.str()[offset-1] << " ";
			sum *= stream.str()[offset-1] - '0';
			idx++;
		}
	} while ( idx < 7 );
	std::cout << std::endl << sum ;
}

#endif /* PROBLEM040_H_ */
