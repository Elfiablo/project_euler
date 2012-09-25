/*
 * Problem022.h
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

#ifndef PROBLEM022_H_
#define PROBLEM022_H_

/*
 * Using Problem022.txt, a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

	For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938  53 = 49714.

	What is the total of all the name scores in the file?

	Answer: 871198282
 */

#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

namespace PROBLEM022 {

std::map<char, unsigned char> mapCodes;
void Init()
{
	for ( int ch = 'A'; ch <= 'Z'; ch++ )
	{
		mapCodes[ch] = ch - 'A' + 1;
	}
}
unsigned GetNameCode(const std::string& name)
{
	unsigned result = 0;
	for ( unsigned i = 0; i < name.length(); i++ )
		result += mapCodes[name[i]];

	return result;
}

}

void Problem022()
{
	using namespace PROBLEM022;
	Init();
	std::ifstream stream("Problem022.txt");


	if ( !stream.is_open() )
	{
		std::cout << "Unable to open file Problem022.txt\n";
	}
	std::string name;
	std::vector<std::string> vecNames;
	while ( std::getline(stream, name, ',') )
	{
		vecNames.push_back( name.substr( 1, name.length()-2 ) );
	}

	std::sort( vecNames.begin(), vecNames.end() );

	unsigned sum = 0;
	for (unsigned i = 0; i < vecNames.size(); i++ )
	{
		sum += (i+1)*GetNameCode(vecNames[i]);
	}
	std::cout << sum << std::endl;
}

#endif /* PROBLEM022_H_ */
