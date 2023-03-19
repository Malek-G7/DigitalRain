#pragma once
#include"digit.h"
#include<vector>
class character : public digit {
public:
	character();
	~character();
	void randomizeDigit();
private:
	static int noOfChars ;
	std::vector<char> characters;
};
