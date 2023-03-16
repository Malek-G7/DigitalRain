#include "digit.h"
#include "Rain.h"
#include <vector>
#include <iostream>
#include <windows.h>
#include <random>

COORD coord;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info = {};

Rain::Rain() {
    this->colors =
    {
        FOREGROUND_INTENSITY | FOREGROUND_GREEN
    };

    this->characters = 
    {
      '0', '1' ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
    };

    GetConsoleScreenBufferInfo(hConsole, &info);
    COORD* p = &info.dwMaximumWindowSize;
    for (int i = 0; i < (p->X); i++) {
        if(i%2 == 0) {
            digit* d = new digit();
            d->setX(i);
            this->digits.push_back(*d);
            /*digit d ;
            d.setX(i);
            this->digits.push_back(d);*/
        }
    }
}

Rain::Rain(std::vector<digit> digits,std::vector<WORD> colors,std::vector<char> characters) {
	this->digits = digits;
    this->colors = colors;
    this->characters = characters;
}

void Rain::setDigits(std::vector<digit> digits) {
	this->digits = digits;
}

void Rain::digitalRain(int y,bool x) {
    GetConsoleScreenBufferInfo(hConsole, &info);
    COORD* p = &info.dwMaximumWindowSize;
    int digitsIterator = 0;
    int j = 0;
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(0, 9);
    e.seed((unsigned int)time(0));
    for (int i = 0; i < p->X; i++) {
        if(i % 2 == x) {
            this->digits.at(digitsIterator).setX(i);
            this->digits.at(digitsIterator).setColor(this->colors.at(j));
            this->digits.at(digitsIterator).setNumber(u(e));
            this->digits.at(digitsIterator).setCh(this->characters.at(u(e)));
            if (j < this->colors.size() - 1) {
                j++;
            }
            else {
                j = 0;
            }
            coord.X = this->digits.at(digitsIterator).getX();
            coord.Y = y;
            SetConsoleCursorPosition(hConsole, coord);
            SetConsoleTextAttribute(hConsole, this->digits.at(digitsIterator).getColor());
            std::cout << this->digits.at(digitsIterator);
            if (digitsIterator < this->digits.size()-1) {
                digitsIterator++;
            }
        }
    }
   
    }
  

