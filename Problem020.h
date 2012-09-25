/*
 * Problem020.h
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

#ifndef PROBLEM020_H_
#define PROBLEM020_H_
#include "BigNumber.h"

/*
 *
 	n! means n x (n - 1) x ... x 3 x 2 x 1

	For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
	and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

	Find the sum of the digits in the number 100!


	Answer: 648
 *
 */

void Problem020()
{
	using namespace BigNumbers;
	BigNumber factorial100(1);
	for ( int i = 2; i < 101; i++ )
	{
		factorial100 = factorial100 * i;
		std::cout << i << "! = ";
		factorial100.print();
	}
	std::cout << factorial100.DigitsSum() << std::endl;
//	const int N = 20;
//	std::vector<int> x(N);
//	x[0] = 1;
//	for (int i=1; i<20; ++i)
//	{
//		for (int j=0; j<N; ++j)
//		{
//			x[j] = i*x[j];
//		}
//		for ( int i = 0; i < N ; i++)
//			std::cout << x[i] << " ";
//
//		std::cout << "\n";
//		for (int j=0; j<N-1; ++j)
//		{
//			x[j+1] += x[j]/10;
//			x[j] = x[j]%10;
//		}
//
//		for ( int i = 0; i < N ; i++)
//			std::cout << x[i];
//
//		std::cout << "\n";
//	}
//
//	int sum = 0;
//	for (int i=N-1; i>=0; --i)
//	{
//		std::cout << x[i];
//		sum += x[i];
//	}
//
//	std::cout <<"\n";
//	std::cout << "sum of digits: " << sum << std::endl;
}
#endif /* PROBLEM020_H_ */
