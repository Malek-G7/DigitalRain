#pragma once
#include"digit.h"
#include<vector>
class character : public digit {
public:
	character();
	char getChar() const;
	void setChar(char);
private:
	static int noOfChars ;
	char ch;
	std::vector<char> characters;
};
