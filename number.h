#pragma once
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
