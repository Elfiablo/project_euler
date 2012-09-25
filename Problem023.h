/*
 * Problem023.h
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

#ifndef PROBLEM023_H_
#define PROBLEM023_H_
#include "Problem012.h"
#include "Problem021.h"

/*
 * A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

	A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

	As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

	Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

	Answer: 4179871
 */


void Problem023()
{
	using PROBLEM012::vecPrimes;
	const int N = 28123;
	PROBLEM012::SievePrimes(N);

	std::vector<int> sigmaFunc(N);
	sigmaFunc[1] = 1;

	int prime, nextPow;
	for ( unsigned p = 0; p < vecPrimes.size(); p++ )
	{
		prime = vecPrimes[p];
		sigmaFunc[prime] = prime+1;
		nextPow = prime*vecPrimes[p];
		while ( nextPow < N ) {
			prime = nextPow;
			nextPow = prime*vecPrimes[p];
			sigmaFunc[prime] = (nextPow - 1)/(vecPrimes[p]-1); //SIGMA(p^n)=(p^(n+1)-1)/(p-1);
		};
	}

	//find sigma for all numbers
	for ( int i = 2; i < N; i++ )
	{
		if (!sigmaFunc[i])
			sigmaFunc[i] = PROBLEM021::GetSumOfDivisors(i, sigmaFunc);
	}

	std::vector<int> vecOddAbundant;
	std::vector<int> vecEvenAbundant;
	for (int i =2 ; i < N; i++ )
	{
		if ( sigmaFunc[i] > 2*i )
		{
			if ( i%2 == 0 )
				vecEvenAbundant.push_back(i);
			else
				vecOddAbundant.push_back(i);
			//std::cout << i << " ";
		}
	}
	std::vector<bool> abundants(N);
	int sum = 0;

	//find the abundants sum less than 48
	for ( unsigned i = 0; i < vecEvenAbundant.size(); i++ )
	{
		if ( vecEvenAbundant[i] > 48 )
			break;

		for ( unsigned j = 0; j < vecEvenAbundant.size(); j++ )
		{
			sum = vecEvenAbundant[i] + vecEvenAbundant[j];
			if ( sum < 48 )
				abundants[sum] = 1;
		}
	}

	// Every even number bigger than 48 is sum of two abundants...
	for (int i = 48; i < N; i += 2)
		abundants[i] = 1;

	//The odd ones from 48 are probably a sum
	for ( unsigned i = 0; i < vecEvenAbundant.size(); i++ )
	{
		for (unsigned j = 0; j < vecOddAbundant.size(); j++ )
		{
			sum = vecEvenAbundant[i] + vecOddAbundant[j];
			if ( sum < N )
				abundants[sum] = 1;
		}
	}
	int64_t sumNotAbundant = 0;
	for ( int i = 1; i < N; i++ )
	{
		if ( !abundants[i] )
			sumNotAbundant += i;
	}
	std::cout << sumNotAbundant;




}


#endif /* PROBLEM023_H_ */
