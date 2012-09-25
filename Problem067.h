/*
 * Problem067.h
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

#ifndef PROBLEM067_H_
#define PROBLEM067_H_

/*
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

	3
	7 4
	2 4 6
	8 5 9 3

	That is, 3 + 7 + 4 + 9 = 23.

	Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'),
	a 15K text file containing a triangle with one-hundred rows.

	NOTE: This is a much more difficult version of Problem 18. It is not possible to try
	every route to solve this problem, as there are 299 altogether! If you could check one trillion (10^12)
	routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)

	Answer: 7273
 */

#include <cstring>
#include <fstream>
#include <vector>
#include <cmath>

void Problem067()
{
	std::ifstream stream("Problem067.txt");

	if ( !stream.is_open() )
	{
		std::cout << "Unable to open file Problem067.txt\n";
	}

	std::vector<int> vecTriangle;

	int num = 0;
	while ( !stream.eof() )
	{
		stream >> num;
		vecTriangle.push_back(num);
	}

	// n(n+1)/2 = SUM. Get n, having SUM
	int ROWS = (-1 + std::sqrt(1+8*vecTriangle.size()))/2;
	unsigned SIZE = (ROWS*(ROWS+1))/2;

	//Just in case check if everything is OK
	if ( SIZE != vecTriangle.size() )
	{
		std::cout << "missmatch = " << ROWS << " " << SIZE << " " << vecTriangle.size();
		exit(1);
	}

	std::vector<int> vecMaxSums(vecTriangle.size());

	int start = vecTriangle.size();
	int end;
	int parentIdx;

	for ( int row = ROWS; row > 1; row-- )
	{
		start -= row;
		end = start + row;
		parentIdx = start-(row-1);
		for ( int i = start; i < end-1; i++, parentIdx++ )
		{
			vecMaxSums[parentIdx] = std::max( vecMaxSums[i]   + vecTriangle[i],
											  vecMaxSums[i+1] + vecTriangle[i+1]);
		}
	}

	std::cout << vecMaxSums[0] + vecTriangle[0];
}


#endif /* PROBLEM067_H_ */
