 /*
 * Problem042.h
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

#ifndef PROBLEM042_H_
#define PROBLEM042_H_

#include "Problem022.h"
#include <cmath>

/*
 * The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1); so the first ten triangle numbers are:

	1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

	By converting each letter in a word to a number corresponding to its alphabetical
	position and adding these values we form a word value. For example,
	the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a
	triangle number then we shall call the word a triangle word.

	Using Problem042.txt (right click and 'Save Link/Target As...'), a 16K text file
	containing nearly two-thousand common English words, how many are triangle words?
	Answer: 162
 */

namespace PROBLEM042{
//n = (sqrt(8*x + 1) - 1)/2;
bool CheckTriangleNum(unsigned num)
{
	num = 8*num + 1;
	//8*x+1 must be odd
	if ( num % 2 == 0 )
		return false;

	unsigned sqrtNum = std::sqrt(num);
	//8*x+1 must be perfect square
	return (sqrtNum * sqrtNum == num);
}
}

void Problem042()
{
	using namespace PROBLEM022;
	using namespace PROBLEM042;
	Init();
	std::ifstream stream("Problem042.txt");

	if ( !stream.is_open() )
	{
		std::cout << "Unable to open file Problem042.txt\n";
	}

	std::string word;
	std::vector<std::string> vecWords;
	while ( std::getline(stream, word, ',') )
	{
		vecWords.push_back( word.substr( 1, word.length()-2 ) );
	}

	unsigned sum=0;
	for (unsigned i = 0; i < vecWords.size(); i++ )
	{
		if ( CheckTriangleNum( GetNameCode(vecWords[i]) ) )
			sum++;
	}
	std::cout << sum << std::endl;
}

#endif /* PROBLEM042_H_ */
