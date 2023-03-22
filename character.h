/*
Malek Geshash
Final year software and Electronics Engineering - ATU
C++ Programming
Digital Rain Project
*/

#ifndef CHARACTER_H
#define CHARACTER_H

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

#endif
