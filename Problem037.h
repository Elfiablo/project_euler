/*
 * Problem037.h
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

#ifndef PROBLEM037_H_
#define PROBLEM037_H_

#include "Problem041.h"
#include <vector>

/*
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
	Answer: 748317
 */

namespace PROBLEM037 {
int64_t primes[] = { 1, 2, 3, 5,  7, 9 };
std::vector<int64_t> vecPrimes(primes, primes+6);
unsigned sum = 0;

bool CheckPrime_LtoR(int64_t num)
{
	do {
		num /= 10;
		if ( !PROBLEM041::CheckPrime(num) )
			return false;
	} while ( num >= 10 );

	return true;
}

void GrowPrimeRtoL(int64_t num, int64_t powOfTen)
{
	if ( !PROBLEM041::CheckPrime(num) )
		return;
	powOfTen *= 10;

	int64_t newNum;
	for ( unsigned i = 0; i < vecPrimes.size(); i++ )
	{
		newNum = vecPrimes[i]*powOfTen + num;
		if ( PROBLEM041::CheckPrime(newNum) )
		{
			if ( CheckPrime_LtoR(newNum) )
			{
				//std::cout << newNum << std::endl;
				sum+= newNum;
			}
			//2 and 5 must be left-most digit
			if ( vecPrimes[i] != 2 && vecPrimes[i] != 5 )
				GrowPrimeRtoL(newNum, powOfTen);
		}
	}
}
}

void Problem037()
{
	using namespace PROBLEM037;
	for ( unsigned i = 0; i < vecPrimes.size(); i++ )
		GrowPrimeRtoL( vecPrimes[i], 1 );

	std::cout << sum;
}


#endif /* PROBLEM037_H_ */
