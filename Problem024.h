/*
 * Problem024.h
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

#ifndef PROBLEM024_H_
#define PROBLEM024_H_

/*
 * A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4.
 * If all of the permutations are listed numerically or alphabetically, we call it lexicographic order.
 * The lexicographic permutations of 0, 1 and 2 are:

	012   021   102   120   201   210

	What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
	Answer: 2783915460
 */


#include <vector>

void Problem024()
{
	const int NUMBERS = 10;
	unsigned factoriels[NUMBERS];

	factoriels[1] = 1;
	for ( int i = 2; i < NUMBERS; i++ )
		factoriels[i] = factoriels[i-1]*i;

	unsigned permutationNeeded = 1000000;
	permutationNeeded -= 1; //Correction, the numbering starts from 0, instead of 1

	int factors[NUMBERS];

	for ( int i = NUMBERS-1; i > 0; i-- )
	{
		factors[i] = permutationNeeded / factoriels[i];
		permutationNeeded %= factoriels[i];
	}

	std::vector<int> vecNumsNotUsed;

	for ( int i = 0; i < NUMBERS; i++ )
		vecNumsNotUsed.push_back(i);

	for ( int i = NUMBERS-1; i > 0; i-- )
	{
		std::cout << vecNumsNotUsed[factors[i]];
		vecNumsNotUsed.erase(vecNumsNotUsed.begin() + factors[i]);
	}
	std::cout << vecNumsNotUsed[0];
}

#endif /* PROBLEM024_H_ */
