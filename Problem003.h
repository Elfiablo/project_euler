/*
 * Problem003.h
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

#ifndef PROBLEM003_H_
#define PROBLEM003_H_

/*
 * The prime factors of 13195 are 5, 7, 13 and 29.
 * What is the largest prime factor of the number 600851475143 ?
 * Answer: 6857
 */

void Problem003()
{
	unsigned long long number = 600851475143L;
	int64_t factor = 2;

	while ( number > 1 )
	{
		while ( number % factor == 0 ){
			number /= factor;
			//std::cout << factor << " ";
		}
		factor++;
	}

	std::cout << factor-1 << std::endl ;
}
#endif /* PROBLEM003_H_ */
