/*
 * Problem048.h
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

#ifndef PROBLEM048_H_
#define PROBLEM048_H_

#include <cstring>
#include "BigNumber.h"

/*
 * The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

	Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
	Answer: 9110846700
 */

namespace PROBLEM048 {
using namespace BigNumbers;
class P048BigNumber : public BigNumber {
private:
	unsigned m_numDigits;
public:
	P048BigNumber(unsigned numDigits) : BigNumber(0, numDigits) { m_numDigits = numDigits; } ;
	P048BigNumber(unsigned smallNumber, unsigned numDigits) : BigNumber(smallNumber, numDigits) { m_numDigits = numDigits; } ;


	P048BigNumber operator+(P048BigNumber aNum)
	{
		P048BigNumber resNum(m_numDigits);
		unsigned maxLen = std::max( m_vecNumber.size(), aNum.m_vecNumber.size() );

		if ( maxLen > m_numDigits )
			maxLen = m_numDigits;

		unsigned result = 0;
		for ( unsigned digit = 0; digit < maxLen ; digit++ )
		{
			if ( digit < m_vecNumber.size() ) {
				result += m_vecNumber[digit];
			}

			if ( digit < aNum.m_vecNumber.size() ) {
				result += aNum.m_vecNumber[digit];
			}

			resNum.m_vecNumber.push_back(result % 10);
			result /= 10;
		}

		while (result && resNum.m_vecNumber.size() < m_numDigits )
		{
			resNum.m_vecNumber.push_back(result % 10);
			result /= 10;
		}

		return resNum;
	}

	P048BigNumber operator*(P048BigNumber aNum)
	{
		std::vector<P048BigNumber> vecNumbers;

		unsigned result;
		for ( unsigned i = 0; i < aNum.m_vecNumber.size(); i++ )
		{
			P048BigNumber tmpNum(m_numDigits);

			for ( unsigned fill = 0; fill < i; fill++ )
				tmpNum.m_vecNumber.push_back(0);

			result = 0;
			for ( unsigned j = 0; j < m_vecNumber.size(); j++ )
			{
				result += m_vecNumber[j] * aNum.m_vecNumber[i];
				tmpNum.m_vecNumber.push_back(result%10);
				result /= 10;
			}

			while (result && tmpNum.m_vecNumber.size() < m_numDigits)
			{
				tmpNum.m_vecNumber.push_back(result%10);
				result/=10;
			}
			vecNumbers.push_back(tmpNum);
		}
		P048BigNumber resNum = vecNumbers[0];
		for ( unsigned i = 1; i < vecNumbers.size(); i++ )
		{
			resNum = resNum + vecNumbers[i];
		}

		return resNum;
	}

	virtual ~P048BigNumber() {}
};

PROBLEM048::P048BigNumber modular_pow_bigNum(int64_t base, int64_t exponent, int numDigits)
{
	PROBLEM048::P048BigNumber result(1, numDigits);
	PROBLEM048::P048BigNumber bigBase(base, numDigits);

	while ( exponent )
	{
		if ( exponent % 2)
			result = result * bigBase;
		exponent >>= 1;
		bigBase = bigBase*bigBase;
	}
	return result;
}
}

int64_t modular_pow(int64_t base, int64_t exponent, int64_t modulus)
{
	int64_t result = 1;
	while ( exponent )
	{
		if ( exponent % 2)
			result = (result*base) % modulus;
		exponent >>= 1;
		base *= base;
		base %= modulus;
	}
	return result;
}

void Problem048()
{
	using namespace PROBLEM048;

	P048BigNumber bigSum(0, 10);
	for ( int i = 1; i <= 1000; i++ )
	{
		if ( i % 10 )
			bigSum = bigSum + modular_pow_bigNum( i, i, 10);
	}
	bigSum.print();
}

#endif /* PROBLEM048_H_ */
