/*
 * Problem021.h
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

#ifndef PROBLEM021_H_
#define PROBLEM021_H_


/*
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
	If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.

	For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

	Evaluate the sum of all the amicable numbers under 10000.
	Answer: 31626

 */
#include <cmath>

#include "Problem012.h"
namespace PROBLEM021 {
int GetSumOfDivisors(int n, std::vector<int>& sigmaFunc)
{
	using PROBLEM012::vecPrimes;
	//Factorize n = p1*p2*p3...*pN
	//return sigmaFunc[p1]*sigmaFunc[p2]*sigmaFunc[p3]...*sigmaFunc[pN]

	unsigned currPrime = 0;
	unsigned divisorsSum = 1;
	unsigned primeFactor = 1;
	while ( n != 1 )
	{
		if ( n % vecPrimes[currPrime] != 0 )
		{
			currPrime++;
			if (primeFactor != 1)
			{
				divisorsSum *= sigmaFunc[primeFactor]; // SIGMA(p1*p2*...*pN) = SIGMA(p1)*SIGMA(p2)*...*SIGMA(pN)
				primeFactor = 1;
			}
		}
		else
		{
			primeFactor *= vecPrimes[currPrime];
			n /= vecPrimes[currPrime];
		}
	}
	divisorsSum *= sigmaFunc[primeFactor];

	return divisorsSum;
}
}

void Problem021()
{
	using namespace PROBLEM021;
	using PROBLEM012::vecPrimes;
	const int N = 10000;
	PROBLEM012::SievePrimes(N);

	std::vector<int> sigmaFunc(10000);
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
			sigmaFunc[i] = GetSumOfDivisors(i, sigmaFunc);
	}

	//find only the amicable number and pairs
	int Da, Db;
	unsigned result = 0;
	for ( int a = 2; a < N; a++ )
	{
		Da = sigmaFunc[a] - a;
		if ( Da < N && Da > a )
		{
			Db = sigmaFunc[Da] - Da;
			if ( Db == a )
			{
				//std::cout << "a = " << a << " D(a) = " << Da << " Db = " << Db << std::endl;
				result += Da + Db;
			}
		}
	}

	std::cout << result;

}

#endif /* PROBLEM021_H_ */
