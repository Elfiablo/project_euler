/*
 * Problem053.h
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

#ifndef PROBLEM053_H_
#define PROBLEM053_H_

/*
 * There are exactly ten ways of selecting three from five, 12345:

	123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

	In combinatorics, we use the notation, 5C3 = 10.

	In general,

	nCr = n!/r!(n-r)! ,where r <= n, n! = nx(n-1)x...x3x2x1, and 0! = 1.
	It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

	How many, not necessarily distinct, values of  nCr, for 1 <= n <= 100, are greater than one-million?
	Answer: 4075
 */

void Problem053()
{
	const int N = 100;
	const unsigned VALUE = 1000000;
	unsigned counter = 0;
	unsigned pascalTriangle[N+1][N+1];

	pascalTriangle[0][0] = 1;

	for ( int n = 1; n <= N; n++ )
	{
		pascalTriangle[n][0] = 1;
		pascalTriangle[n][n] = 1;
		for ( int k = 1; k < n; k++ )
		{
			pascalTriangle[n][k] = pascalTriangle[n-1][k-1] + pascalTriangle[n-1][k];

			if ( pascalTriangle[n][k] > VALUE )
			{
				pascalTriangle[n][k] = VALUE;
				counter++;
			}
		}
	}
	std::cout << counter;
}


#endif /* PROBLEM053_H_ */
