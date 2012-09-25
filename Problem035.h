/*
 * Problem035.h
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

#ifndef PROBLEM035_H_
#define PROBLEM035_H_

/*
 * The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

	There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

	How many circular primes are there below one million?
	Answer: 55
 */

#include <cstring>
#include <vector>
#include <algorithm>

void Problem035()
{
	//Sieve primes
	const unsigned SIZE = 1000000;
	bool primes[SIZE];
	memset(primes, 1, sizeof(primes));
	primes[0] = false;
	primes[1] = false;
	unsigned num;
	std::vector<unsigned> vecCyclicPrimes;
	for ( unsigned i = 2; i < SIZE; i++ )
	{
		if ( !primes[i] )
			continue;
		//Sieve of Erathosthene's
		for ( unsigned k = i+i; k < SIZE; k+=i) primes[k] = false;
		////////////////////////

		//Reduce the primes and remove those with any of the digits coprime to 2 or 5
		num = i/10;
		while ( num )
		{
			if ( !(num % 2) || !(num % 5) )
			{
				primes[i] = false;
				break;
			}
			num /= 10;
		}
		//////////////
	}

	unsigned numCyclicPrimes = 5; // primes 2, 3, 5, 7, 11
//	for ( unsigned i = 2; i < 12; i++ )
//	{
//		if ( primes[i] )
//			vecCyclicPrimes.push_back(i);
//	}

	unsigned delims[7] = { 1, 1, 10, 100, 1000, 10000, 100000 };
	unsigned idx = 2;

//	unsigned rotatedPrimes[6] = { 0, 0, 0, 0, 0, 0 };
	unsigned groupIdx = 0;
	unsigned digit = 0;

	for ( unsigned i = 13; i < SIZE; i++ )
	{
		if ( primes[i] )
		{
			num = i;
			while ( (digit = num/delims[idx]) > 10 )
				idx++;

			groupIdx = 1;
	//		rotatedPrimes[groupIdx++] = i;
			for ( unsigned j = 0; j < idx-1; j++ )
			{
				num = (num%delims[idx])*10 + digit;
				if ( primes[num] )
				{
					//rotatedPrimes[groupIdx++] = num;
					groupIdx++;
					primes[num] = false;
				}
				digit = num/delims[idx];
			}

			if ( groupIdx == idx )
			{
				numCyclicPrimes += groupIdx;
				// vecCyclicPrimes.insert(vecCyclicPrimes.end(), rotatedPrimes, rotatedPrimes+groupIdx);
			}
		}
	}

//	std::sort(vecCyclicPrimes.begin(), vecCyclicPrimes.end());
//	for (unsigned i = 0; i < vecCyclicPrimes.size(); i++ )
//	{
//		std::cout << vecCyclicPrimes[i] << " ";
//	}
//	std::cout << "\nNum: " << vecCyclicPrimes.size();
	std::cout << "Num: " << numCyclicPrimes;
}

#endif /* PROBLEM035_H_ */
