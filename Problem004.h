/*
 * Problem004.h
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

#ifndef PROBLEM004_H_
#define PROBLEM004_H_

#include <sstream>

/*
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * Answer: 906609
 */

namespace PROBLEM_004{
bool checkPalyndrome(int num)
{
	std::stringstream stream;
	stream << num;

	std::string strNum( stream.str() );

	unsigned len = strNum.length();
	for ( unsigned i = 0; i < len/2; i++ )
	{
		if ( strNum[i] != strNum[len - i - 1] )
			return false;
	}
	return true;

}
}

void Problem004()
{
	using namespace PROBLEM_004;

	unsigned unCurr = 0;
	unsigned unMax = 0;

	for ( int a = 999; a >= 899; a-- )
	{
		for ( int b = a; b >= 899; b--)
		{
			if ( checkPalyndrome(a*b) )
			{
				//std::cout << a << " * " << b << " = "<< a*b << std::endl;
				unCurr = a*b;
				if ( unCurr > unMax )
					unMax = unCurr;
			}
		}
	}

	std::cout << unMax << std::endl;
}

#endif /* PROBLEM004_H_ */
