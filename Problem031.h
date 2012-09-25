/*
 * Problem031.h
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

#ifndef PROBLEM031_H_
#define PROBLEM031_H_

/*
 * In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

	1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).
	It is possible to make £2 in the following way:

	1£1 + 150p + 220p + 15p + 12p + 31p
	How many different ways can £2 be made using any number of coins?
	Answer: 73682
 */
#include <set>
namespace PROBLEM031{

const int MAX_DENOM = 200+1;
int coins[9] = { 0, 1, 2, 5, 10, 20, 50, 100, 200 };

std::set<int> setCoins(coins, coins+9);
int F[MAX_DENOM][MAX_DENOM];
void init()
{
	for ( int i = 0; i < MAX_DENOM; i++ )
		for ( int j = 0; j < MAX_DENOM; j++ )
			F[i][j] = 0;
}

int count(int sum, int maxDenom)
{
	if ( sum <= 0 )
		return 0;
	if ( F[sum][maxDenom] > 0 )
		return F[sum][maxDenom];
	else
	{
		if (sum < maxDenom)
			maxDenom = sum;
		if ( sum == maxDenom && setCoins.find(maxDenom) != setCoins.end() )
			F[sum][maxDenom] = 1;

		std::set<int>::iterator it = setCoins.find(maxDenom);
		unsigned currCoin;
		for ( ; it != setCoins.begin(); it-- )
		{
			currCoin = *it;
			F[sum][maxDenom] += count(sum-currCoin, currCoin);
		}
	}
	return F[sum][maxDenom];
}

}

void Problem031()
{
	PROBLEM031::init();
	std::cout << PROBLEM031::count(200, 200);
}

#endif /* PROBLEM031_H_ */
