#pragma once
#include "digit.h"
#include <vector>
#include <windows.h>

class Rain {
public :
	Rain();
	Rain(std::vector<digit>,std::vector<WORD>,std::vector<char>,COORD,HANDLE,CONSOLE_SCREEN_BUFFER_INFO,int,int);
	~Rain();
	void setDigits(std::vector<digit>);
	std::vector<digit> getDigits() const { return digits; };
	int getDigitsSize() const { return digits.size(); };
	int randomize(int , int,int);
	void digitalRain();
private:
	COORD coord;
	HANDLE hConsole;
	CONSOLE_SCREEN_BUFFER_INFO info;
	std::vector<digit> digits;
	int NoOfDigits;
	std::vector<WORD> colors;
	std::vector<char> characters; 
	int runtime;
};
