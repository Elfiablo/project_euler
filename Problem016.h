/*
 * Problem016.h
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

#ifndef PROBLEM016_H_
#define PROBLEM016_H_

#include "BigNumber.h"

/*
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

	What is the sum of the digits of the number 2^1000?

	Answer: 1366
 */

void Problem016()
{
	using namespace BigNumbers;
	BigNumber num(1024);
	BigNumber result(1);

	for (int i = 0; i < 100; i++ )
	{
		result = result*num;
	}
	result.print();
	std::cout << result.DigitsSum() << std::endl;
}




#endif /* PROBLEM016_H_ */
