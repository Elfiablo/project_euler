/*
 * Problem034.h
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

#ifndef PROBLEM034_H_
#define PROBLEM034_H_

/*
 *145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

	Find the sum of all numbers which are equal to the sum of the factorial of their digits.

	Note: as 1! = 1 and 2! = 2 are not sums they are not included.
	Answer: 40730
 */

void Problem034()
{
	unsigned factorials[10];

	factorials[0] = 1;
	factorials[1] = 1;
	for ( int i = 2; i < 10; i++ )
	{
		factorials[i] = factorials[i-1]*i;
	}

	int num, sum, result = 0;
	for ( int i = 145; i < 10000000; i++ )
	{
		num = i;
		sum = 0;
		while(num)
		{
			sum += factorials[num%10];
			num/=10;
			if ( i < sum )
				break;

		}
		if (i == sum)
		{
			//std::cout << i << std::endl;
			result += sum;
		}
	}
	std::cout << result;

}


#endif /* PROBLEM034_H_ */
