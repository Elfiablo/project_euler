/*
 * Problem015.h
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

#ifndef PROBLEM015_H_
#define PROBLEM015_H_

/*
 * Starting in the top left corner of a 2x2 grid, there are 6 routes (without backtracking) to the bottom right corner.
 	How many routes are there through a 20x20 grid?
	Answer: 137846528820
 */

//1x1 grid has 2 rows. 2x1 grid has 3. 2x2 has 2x1 + 2x1. 3x1 has 4. 3x2 has 2x2 + 3x1 - 10 and etc...
void Problem015() {
	const unsigned N = 20;
	int64_t grid[N][N];

	for ( unsigned i = 0; i < N; i++ )
		grid[0][i] = grid[i][0] = i+2;
	for ( unsigned i = 1; i < N; i++ )
		for ( unsigned j = 1; j < N; j++ )
			grid[i][j] = grid[i-1][j] + grid[i][j-1];

	std::cout << grid[N-1][N-1];
}


#endif /* PROBLEM015_H_ */
