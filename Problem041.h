/*
 * Project041.h
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

#ifndef PROBLEM041_H_
#define PROBLEM041_H_
/*
 * We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

	What is the largest n-digit pandigital prime that exists?
	Answer: 7652413
 */

#include <cmath>
namespace PROBLEM041 {
bool CheckPrime(int64_t n)
{
	if (/* n%2 == 0 || n%5 == 0 || */n == 1)
		return false;
	int sqrtN = std::sqrt(n);
	for ( int i = 2; i <= sqrtN; i++ )
		if ( n % i == 0)
			return false;

	return true;
}

bool formPrimePandigital(bool* used, int numDigits, std::string& strNum, int depth = 1)
{
	if ( depth == numDigits )
	{
		std::stringstream stream;
		stream << strNum;
		int64_t num;
		stream >> num;
		return CheckPrime(num);
	}

	for ( unsigned i = numDigits; i > 0 ; i-- )
	{
		if ( !used[i] )
		{
			used[i] = true;
			strNum[depth] = i + '0';
			if ( formPrimePandigital(used, numDigits, strNum, depth+1 ) )
				return true;
			used[i] = false;
		}
	}
	return false;
}

}

void Problem041()
{
	using namespace PROBLEM041;
	bool used[10];

	for ( int i = 7; i > 0; i-- )
	{
		used[i] = true;
		std::string strNum = "0000000";
		strNum[0] = i + '0';
		if ( formPrimePandigital(used, 7, strNum) )
		{
			std::cout << strNum << std::endl;
			break;
		}
		used[i] = false;
	}
}

#endif /* PROBLEM041_H_ */
