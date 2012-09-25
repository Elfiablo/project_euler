/*
 * Problem014.h
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

#ifndef PROBLEM014_H_
#define PROBLEM014_H_

/*
 * The following iterative sequence is defined for the set of positive integers:

	n -> n/2 (n is even)
	n -> 3n + 1 (n is odd)

	Using the rule above and starting with 13, we generate the following sequence:

	13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

	Which starting number, under one million, produces the longest chain?

	NOTE: Once the chain starts the terms are allowed to go above one million.
	Answer: 837799
 */
#include <cstring>

void Problem014()
{
	short mapSteps[4000000];
	memset(mapSteps, 0, sizeof(mapSteps));
	unsigned steps;
	unsigned workNum;
	unsigned maxSteps = 0;
	unsigned maxStartNum = 0;
	mapSteps[1] = 1;
	mapSteps[2] = 2;
	for ( unsigned num = 2; num < 1000000; num++ )
	{
		steps = 1;
		workNum = num;
		while ( workNum != 1 ) {
			workNum = (workNum % 2) ? (3*workNum+1) : (workNum/2);
			if ( workNum < 4000000 && mapSteps[workNum] )
			{
				steps += mapSteps[workNum];
				break;
			}
			steps++;
		}

		mapSteps[num] = steps;

		if ( steps > maxSteps )
		{
			maxSteps = steps;
			maxStartNum = num;
		}
	}

	std::cout << maxStartNum << " requires " << maxSteps << " steps.";

}

#endif /* PROBLEM014_H_ */
