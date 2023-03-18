#pragma once
#include"digit.h"
#include<vector>
class number : public digit {
public:
	number();
	char getNum() const;
	void setNum(char);
private: 
	char num ;
	static int noOfNum;
	std::vector<char> numbers;
};
