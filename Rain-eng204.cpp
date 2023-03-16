#include "digit.h"
#include "Rain.h"
#include <vector>
#include <iostream>
#include <windows.h>
COORD coord;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info = {};

Rain::Rain() {
    std::vector<digit> digits;
    GetConsoleScreenBufferInfo(hConsole, &info);
    COORD* p = &info.dwMaximumWindowSize;
    for (int i = 0; i < (p->X); i++) {
        if(i%2 == 0) {
            digit* d = new digit();
            d->setX(i);
            digits.push_back(*d);
        }
    }
    this->digits = digits;
}

Rain::Rain(std::vector<digit> digits) {
	this->digits = digits;
}

void Rain::setDigits(std::vector<digit> digits) {
	this->digits = digits;
}

void Rain::digitalRain(int y,bool x) {
    GetConsoleScreenBufferInfo(hConsole, &info);
    COORD* p = &info.dwMaximumWindowSize;
    for (int i = 0; i < (p->X)-1; i++) {
        if (x== true && i % 2 != 0) {
            this->digits.at(0).setX(i);
        }
        if (x==false && i % 2 == 0) {
            this->digits.at(0).setX(i);
        }
        coord.X = this->digits.at(0).getX();
        coord.Y = y;
        SetConsoleCursorPosition(hConsole, coord);
        std::cout << this->digits.at(0).getNumber();
    }
    
}
