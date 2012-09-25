/*
 * Problem009.h
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

#ifndef PROBLEM009_H_
#define PROBLEM009_H_

/*
 * A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
 *	a2 + b2 = c2
 *	For example, 32 + 42 = 9 + 16 = 25 = 52.
 *	There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *	Find the product abc.
 *  Answer: 31875000
 */

void Problem009()
{
	unsigned b = 0;
	unsigned numerator = 0;
	unsigned denumerator = 0;

	for ( unsigned a = 1; a < 500; a++ )
	{
		numerator = (500000 - 1000*a);
		denumerator = (1000-a);

		b = numerator/denumerator;
		if ( b * denumerator == numerator && b > a )
		{
			std::cout << "a = " << a << "; b = " << b << "; c = " << 1000 - (a+b) << "; ";
			std::cout << "a*b*c = " << a*b*(1000-(a+b)) << std::endl;
		}
	}
}

#endif /* PROBLEM009_H_ */
