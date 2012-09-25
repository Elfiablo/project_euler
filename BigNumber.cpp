/*
 * BigNumber.cpp
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

#include "BigNumber.h"

namespace BigNumbers {

BigNumber::BigNumber() : m_vecNumber(0) {
	m_vecNumber.reserve(128);
}

BigNumber::BigNumber(unsigned smallNumber) : m_vecNumber(0) {
	m_vecNumber.reserve(128);
	while (smallNumber)
	{
		m_vecNumber.push_back(smallNumber%10);
		smallNumber /= 10;
	}
}

BigNumber::BigNumber(unsigned smallNumber, unsigned numDigits) : m_vecNumber(0) {
	m_vecNumber.reserve(numDigits);
	while (smallNumber)
	{
		m_vecNumber.push_back(smallNumber%10);
		smallNumber /= 10;
	}
}

BigNumber BigNumber::operator+(BigNumber aNum)
{
	BigNumber resNum;
	unsigned maxLen = std::max( m_vecNumber.size(), aNum.m_vecNumber.size() );

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

	while (result)
	{
		resNum.m_vecNumber.push_back(result % 10);
		result /= 10;
	}

	return resNum;
}

BigNumber BigNumber::operator*(BigNumber aNum)
{
	std::vector<BigNumber> vecNumbers;

	unsigned result;
	for ( unsigned i = 0; i < aNum.m_vecNumber.size(); i++ )
	{
		BigNumber tmpNum;

		for ( unsigned fill = 0; fill < i; fill++ )
			tmpNum.m_vecNumber.push_back(0);

		result = 0;
		for ( unsigned j = 0; j < m_vecNumber.size(); j++ )
		{
			result += m_vecNumber[j] * aNum.m_vecNumber[i];
			tmpNum.m_vecNumber.push_back(result%10);
			result /= 10;
		}

		while (result)
		{
			tmpNum.m_vecNumber.push_back(result%10);
			result/=10;
		}
		vecNumbers.push_back(tmpNum);
	}
	BigNumber resNum = vecNumbers[0];
	for ( unsigned i = 1; i < vecNumbers.size(); i++ )
	{
		resNum = resNum + vecNumbers[i];
	}

	return resNum;
}

void BigNumber::print(){
	for (unsigned i = 0; i < m_vecNumber.size(); i++)
	{
		std::cout << m_vecNumber[m_vecNumber.size()-1-i];
	}
	std::cout << std::endl;
}

unsigned BigNumber::DigitsSum()
{
	unsigned result = 0;
	for (unsigned i = 0; i < m_vecNumber.size(); i++)
		result += m_vecNumber[i];
	return result;
}

unsigned BigNumber::DigitsNum()
{
	return m_vecNumber.size();
}

BigNumber::~BigNumber() {
	// TODO Auto-generated destructor stub
}

} /* namespace BigNumbers */
