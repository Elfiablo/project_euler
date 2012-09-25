/*
 * Problem030.h
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

#ifndef PROBLEM030_H_
#define PROBLEM030_H_

/*
 * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

	1634 = 14 + 64 + 34 + 44
	8208 = 84 + 24 + 04 + 84
	9474 = 94 + 44 + 74 + 44
	As 1 = 14 is not a sum it is not included.

	The sum of these numbers is 1634 + 8208 + 9474 = 19316.

	Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

	Answer: 443839
 */

void Problem030()
{
	unsigned fifthPowers[10];
	for ( int i = 0; i < 10; i++ )
	{
		fifthPowers[i] = i*i*i*i*i;
	}
	unsigned sum = 0;
	unsigned result = 0;
	int num;
	for ( int i = 1000; i < 354294; i++ )
	{
		num = i;
		sum = 0;
		while(num)
		{
			sum += fifthPowers[num%10];
			num/=10;
		}
		if (i == sum)
		{
			result += sum;
		}
	}
	std::cout << result;
}

#endif /* PROBLEM030_H_ */
