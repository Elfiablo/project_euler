/*
 * Problem018.h
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

#ifndef PROBLEM018_H_
#define PROBLEM018_H_

#include <cstring>
/*
 * By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

	3
	7 4
	2 4 6
	8 5 9 3

	That is, 3 + 7 + 4 + 9 = 23.

	Find the maximum total from top to bottom of the triangle below:

	75
	95 64
	17 47 82
	18 35 87 10
	20 04 82 47 65
	19 01 23 75 03 34
	88 02 77 73 07 63 67
	99 65 04 28 06 16 70 92
	41 41 26 56 83 40 80 70 33
	41 48 72 33 47 32 37 16 94 29
	53 71 44 65 25 43 91 52 97 51 14
	70 11 33 28 77 73 17 78 39 68 17 57
	91 71 52 38 17 14 91 43 58 50 27 29 48
	63 66 04 68 89 53 67 30 73 16 69 87 40 31
	04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

	NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route.
	However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be
	solved by brute force, and requires a clever method! ;o)

	Answer: 1074
 */

void Problem018()
{
	const int ROWS = 15;
	const int SIZE = (ROWS*(ROWS+1))/2;
//	int nTriangle[SIZE] = {/*  0*/ 3,
//						   /*  1*/ 7, 4,
//						   /*  3*/ 2, 4, 6,
//						   /*  6*/ 8, 5, 9, 3 };
	int nTriangle[SIZE] = {/*  0*/ 75,
						   /*  1*/ 95, 64,
						   /*  3*/ 17, 47, 82,
						   /*  6*/ 18, 35, 87, 10,
						   /* 10*/ 20, 04, 82, 47, 65,
						   /* 15*/ 19, 01, 23, 75, 03, 34,
						   /* 21*/ 88, 02, 77, 73, 07, 63, 67,
						   /* 28*/ 99, 65, 04, 28, 06, 16, 70, 92,
						   /* 36*/ 41, 41, 26, 56, 83, 40, 80, 70, 33,
						   /* 45*/ 41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
						   /* 55*/ 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
						   /* 66*/ 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
						   /* 78*/ 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
						   /* 91*/ 63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
						   /*105*/ 04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23 };

	int nMaxSums[SIZE];
	std::memset(nMaxSums, 0, sizeof(nMaxSums));

	int start = SIZE;
	int end;
	int parentIdx;

	for ( int row = ROWS; row > 1; row-- )
	{
		start -= row;
		end = start + row;
		parentIdx = start-(row-1);
		for ( int i = start; i < end-1; i++, parentIdx++ )
		{
			nMaxSums[parentIdx] = std::max( nMaxSums[i]   + nTriangle[i],
											nMaxSums[i+1] + nTriangle[i+1]);
		}
	}

	std::cout << nMaxSums[0] + nTriangle[0];
}

#endif /* PROBLEM018_H_ */
