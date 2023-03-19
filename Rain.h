#pragma once
#include "digit.h"
#include <vector>
#include <windows.h>
#include "number.h"
#include "character.h"
class Rain {
public :
	Rain();
	Rain(std::vector<digit>,std::vector<WORD>,COORD,HANDLE,CONSOLE_SCREEN_BUFFER_INFO,int,int);
	~Rain();
	void setDigits(std::vector<digit>);
	std::vector<digit> getDigits() const { return digits; };
	int getDigitsSize() const { return digits.size(); };
	int randomize(int , int,int);
	void digitalRain();
	void digitalRain_num();
	void digitalRain_char();
private:
	COORD coord;
	HANDLE hConsole;
	CONSOLE_SCREEN_BUFFER_INFO info;
	std::vector<digit> digits;
	std::vector<number> numbers ;
	std::vector<character> characters;
	int NoOfDigits;
	std::vector<WORD> colors;
	int runtime;
};
