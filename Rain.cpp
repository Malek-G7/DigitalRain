#include "digit.h"
#include "Rain.h"
#include <vector>
#include <iostream>
#include <windows.h>
#include <random>
#include <chrono>

Rain::Rain() {
    this->coord.Y = 0;
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    this->info = {};
    this->runtime = 10000;
    this->colors =
    {
        FOREGROUND_INTENSITY | FOREGROUND_GREEN
    };

    this->characters = 
    {
      '0', '1' 
    };

    this->NoOfDigits=10;
    for (int i = 0; i < NoOfDigits; i++) {
         digit d ;
         d.setX(i);
         this->digits.push_back(d);
    }
}

Rain::Rain(std::vector<digit> digits,std::vector<WORD> colors,std::vector<char> characters, COORD coord, HANDLE hConsole, CONSOLE_SCREEN_BUFFER_INFO info, int NoOfDigits,int runtime) {
	this->digits = digits;
    this->colors = colors;
    this->characters = characters;
    this->coord = coord;
    this->hConsole = hConsole;
    this->info = info;
    this->NoOfDigits = NoOfDigits;
    this->runtime = runtime;
}

void Rain::setDigits(std::vector<digit> digits) {
	this->digits = digits;
}

void Rain::digitalRain() {
    while (this->coord.Y<this->runtime) {
        GetConsoleScreenBufferInfo(this->hConsole, &info);
        COORD* p = &info.dwMaximumWindowSize;
        int randomColNo = randomize(1, digits.size() - 1, 0);
        for (int i = 0; i < randomColNo; i++) {
            try {
                this->digits.at(i).setX(randomize(0, p->X, i));
                this->digits.at(i).setColor(this->colors.at(randomize(0, this->colors.size() - 1, i)));
                this->digits.at(i).setCh(this->characters.at(randomize(0, this->characters.size() - 1, i)));
                coord.X = this->digits.at(i).getX();
            }
            catch (std::out_of_range & e) {
                std::cout << " Exception: " << e.what() << std::endl;
            }
            SetConsoleCursorPosition(hConsole, coord);
            SetConsoleTextAttribute(hConsole, this->digits.at(i).getColor());
            std::cout << this->digits.at(i);
        }
        coord.Y++;
        Sleep(25);
    }
 }

int Rain::randomize(int start, int end,int i) {
    std::default_random_engine e;
    std::uniform_int_distribution<int> u(start,end);
    e.seed((unsigned int)time(0)+i);
    return u(e);
}
  

