/*
 * Problem097.h
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

#ifndef PROBLEM097_H_
#define PROBLEM097_H_

#include "Problem048.h"
/*
 * The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593-1;
 * it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p-1, have been found which contain more digits.

	However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433x2^7830457+1.

	Find the last ten digits of this prime number.
	Answer: 8739992577
 */

void Problem097()
{
	using namespace PROBLEM048;

	P048BigNumber one(1, 10);
	P048BigNumber powerOfTwo(2, 10);
	P048BigNumber number(28433, 10);
	powerOfTwo = modular_pow_bigNum( 2, 7830457, 10);
	//powerOfTwo = modular_pow_bigNum( 2, 20, 10);
	//powerOfTwo.print();


	P048BigNumber result = (number * powerOfTwo) + one;

	result.print();
}

#endif /* PROBLEM097_H_ */
