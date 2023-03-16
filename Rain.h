#pragma once
#include "digit.h"
#include <vector>
#include <windows.h>

class Rain {
public :
	Rain();
	Rain(std::vector<digit>,std::vector<WORD>,std::vector<char>);
	void setDigits(std::vector<digit>);
	std::vector<digit> getDigits() const { return digits; };
	int getDigitsSize() const { return digits.size(); };

	void digitalRain(int,bool);
private:
	std::vector<digit> digits;
	std::vector<WORD> colors;
	std::vector<char> characters; 
};