/*
 * Problem001.h
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

#ifndef PROBLEM001_H_
#define PROBLEM001_H_

/*
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 * Answer: 233168
 */

void Problem001()
{
	long sum = 0;
	for ( int i = 1; i < 1000; i++ )
	{
		if ( !(i%3) || !(i%5) )
			sum += i;
	}
	std::cout << sum << std::endl;
}

#endif /* PROBLEM001_H_ */
