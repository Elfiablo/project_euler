/*
 * BigNumber.h
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

#ifndef BIGNUMBER_H_
#define BIGNUMBER_H_

#include <string>
#include <iostream>
#include <vector>

namespace BigNumbers {

class BigNumber {
protected:
	std::vector<short> m_vecNumber;
public:
	BigNumber();
	BigNumber(unsigned smallNumber);
	BigNumber(unsigned smallNumber, unsigned numDigits);

	BigNumber operator+(BigNumber aNum);
	BigNumber operator*(BigNumber aNum);

	void print();
	unsigned DigitsSum();
	unsigned DigitsNum();

	virtual ~BigNumber();
};

} /* namespace BigNumbers */
#endif /* BIGNUMBER_H_ */
