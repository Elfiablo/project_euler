/*
 * Problem028.h
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

#ifndef PROBLEM028_H_
#define PROBLEM028_H_
/*
 *Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

	It can be verified that the sum of the numbers on the diagonals is 101.

	What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

	Answer: 669171001
 */
void Problem028()
{
	// A1 = 1;
	// An = An-1 + 8*n - 14, n >= 2
	const int MAX_N = 501;
	int An = 1;
	unsigned sum = 0;
	for ( int n = 2; n <= MAX_N; n++ )
	{
		An += 8*n - 14;
		sum += An;
	}

	std::cout << 1 + 4*sum + 6*MAX_N*(MAX_N-1) << std::endl;


}


#endif /* PROBLEM028_H_ */
