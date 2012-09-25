/*
 * Problem017.h
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

#ifndef PROBLEM017_H_
#define PROBLEM017_H_

/*
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

	If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

	NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen)
	contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.

	Answer: 21124
 */

#include <map>
#include <iostream>

namespace PROBLEM017
{
	std::map< int, std::string > mapWords;
	std::string strHundred;
	std::string strAnd;
	std::string strOneThousand;

void Init()
{
	mapWords[1] = "one";
	mapWords[2] = "two";
	mapWords[3] = "three";
	mapWords[4] = "four";
	mapWords[5] = "five";
	mapWords[6] = "six";
	mapWords[7] = "seven";
	mapWords[8] = "eight";
	mapWords[9] = "nine";
	mapWords[10] = "ten";
	mapWords[11] = "twelve";
	mapWords[12] = "twenty";
	mapWords[13] = "thirteen";
	mapWords[14] = "fourteen";
	mapWords[15] = "fifteen";
	mapWords[16] = "sixteen";
	mapWords[17] = "seventeen";
	mapWords[18] = "eighteen";
	mapWords[19] = "nineteen";
	mapWords[20] = "twenty";
	mapWords[30] = "thirty";
	mapWords[40] = "forty";
	mapWords[50] = "fifty";
	mapWords[60] = "sixty";
	mapWords[70] = "seventy";
	mapWords[80] = "eighty";
	mapWords[90] = "ninety";
	mapWords[1000] = "onethousand";
	strHundred = "hundred";
	strAnd = "and";
	//strOneThousand = "onethousand";
}

std::string GetString( int number, unsigned& sum )
{
	if ( !number )
		return "";

	std::string result;

	if ( mapWords.find(number) != mapWords.end() )
	{
		sum += mapWords[number].length();
		return mapWords[number];
	}

	if ( number < 100 )
	{
		result = GetString( (number/10)*10, sum);

		if ( number%10 )
			result += "-" + GetString( number%10, sum);

		return result;
	}
	//else
	result = mapWords[number/100] + " " + strHundred;
	sum += mapWords[number/100].length() + strHundred.length();
	if ( number % 100 )
	{
		sum += strAnd.length();
		result += " and " + GetString( number % 100, sum );
	}
	return result;
}
}

void Problem017()
{
	using namespace PROBLEM017;
	Init();



	unsigned sumAll = 0;

	std::string strNum;

	for ( int i = 1; i < 1001; i++ )
	{
		//sumAll = 0;
		strNum = GetString(i, sumAll);
		//std::cout << i << " -> " <<  strNum << " (" << sumAll << ")" << std::endl;
	}
	std::cout << sumAll << std::endl;

	sumAll = 0;

	//working formula: S(1-99) = 10*S(1-9) + S(10-19) + 10*(S(20) + S(30) + ... + S(90))
	//		   		   S(100-1000) = 9*S(1-99) + 100*S(1-9) + 9*100*S('hundred') + 9*99*S('and') + S('one thousand')
	//		   		   S(1-1000) = 10*S(1-99) + 100*S(1-9) + 9*100*S('hundred') + 9*99*S('and') + S('one thousand')
	//
	//	unsigned sum1to9 = 0;
	//	unsigned sum1to99 = 0;
	//
	//	for ( int i = 1; i < 10; i++ )
	//	{
	//		GetString(i, sum1to9);
	//	}
	//
	//	sum1to99 = sum1to9;
	//	for ( int i = 10; i < 100; i++ )
	//	{
	//		GetString(i, sum1to99);
	//	}
	//
	//	std::cout << "S(1-9) = " << sum1to9 << "; S(1-99) = " << sum1to99 << "\n";
	//
	//	sumAll = 10*sum1to99 + 100*sum1to9 + 900*strHundred.length() + 9*99*strAnd.length() + mapWords[1000].length();
	//	std::cout << sumAll;




}


#endif /* PROBLEM017_H_ */
