/*
 * Problem025.h
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

#ifndef PROBLEM025_H_
#define PROBLEM025_H_

/*
 * The Fibonacci sequence is defined by the recurrence relation:

	Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
	Hence the first 12 terms will be:

	F1 = 1
	F2 = 1
	F3 = 2
	F4 = 3
	F5 = 5
	F6 = 8
	F7 = 13
	F8 = 21
	F9 = 34
	F10 = 55
	F11 = 89
	F12 = 144
	The 12th term, F12, is the first term to contain three digits.

	What is the first term in the Fibonacci sequence to contain 1000 digits?

	Answer: 4782
 */

#include "BigNumber.h"

void Problem025()
{
	using namespace BigNumbers;

	BigNumber Fn(1);
	BigNumber Fn1(1);
	BigNumber Fn2;

	unsigned counter = 2;

	while ( Fn2.DigitsNum() < 1000 )
	{
		Fn2 = Fn + Fn1;
		Fn = Fn1;
		Fn1 = Fn2;
		counter++;
	}
	std::cout << counter << std::endl;
	Fn2.print();
}

#endif /* PROBLEM025_H_ */
