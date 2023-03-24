/*
Malek Geshash
Final year software and Electronics Engineering - ATU
C++ Programming
Digital Rain Project
*/

#ifndef NUMBER_H
#define NUMBER_H

#include"digit.h"
#include<vector>

class number : public digit {
public:
	number();
	~number();
	void randomizeDigit();
private: 
	static int noOfNum;
	std::vector<char> numbers;
};

#endif