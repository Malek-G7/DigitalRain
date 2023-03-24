/*

*/

#include "digit.h"
#include "Rain.h"
#include <vector>
#include <iostream>
#include <windows.h>
#include <random>
#include <chrono>
#include "number.h"
#include "character.h"

Rain::Rain() {
    this->coord.Y = 0;
    this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    this->info = {};
    this->runtime = 1000;
    this->colors =
    {
        FOREGROUND_INTENSITY | FOREGROUND_GREEN
    };
    this->NoOfDigits=10;
}

Rain::Rain(std::vector<digit> digits,std::vector<WORD> colors, COORD coord, HANDLE hConsole, CONSOLE_SCREEN_BUFFER_INFO info, int NoOfDigits,int runtime) {
	this->digits = digits;
    this->colors = colors;
    this->coord = coord;
    this->hConsole = hConsole;
    this->info = info;
    this->NoOfDigits = NoOfDigits;
    this->runtime = runtime;
}

Rain::~Rain() {
    std::cout << std::endl << "Rain destructor called" << std::endl;
}

void Rain::setDigits(std::vector<digit> digits) {
	this->digits = digits;
}

void Rain::digitalRain_char() {
    for (auto i = 0; i < NoOfDigits; i++) {
        character ch;
        this->characters.push_back(ch);
    }
    while (this->coord.Y<this->runtime) {
        GetConsoleScreenBufferInfo(this->hConsole, &info);
        COORD* p = &info.dwMaximumWindowSize;
        auto randomColNo = randomize(1, characters.size() - 1, 0);
        for (auto i = 0; i < randomColNo; i++) {
            try {
                this->characters.at(i).setX(randomize(0, p->X, i));
                this->characters.at(i).setColor(this->colors.at(randomize(0, this->colors.size() - 1, i)));
                this->characters.at(i).randomizeDigit();
                coord.X = this->characters.at(i).getX();
            }
            catch (std::out_of_range const&e) {
                std::cout << " Exception: " << e.what() << std::endl;
            }
            SetConsoleCursorPosition(hConsole, coord);
            SetConsoleTextAttribute(hConsole, this->characters.at(i).getColor());
            std::cout << this->characters.at(i);
        }
        coord.Y++;
        Sleep(25);
    }
}

void Rain::digitalRain_num() {
    for (auto i = 0; i < NoOfDigits; i++) {
        number num;
        this->numbers.push_back(num);
    }
    while (this->coord.Y < this->runtime) {
        GetConsoleScreenBufferInfo(this->hConsole, &info);
        COORD* p = &info.dwMaximumWindowSize;
        auto randomColNo = randomize(1, numbers.size() - 1, 0);
        for (auto i = 0; i < randomColNo; i++) {
            try {
                this->numbers.at(i).setX(randomize(0, p->X, i));
                this->numbers.at(i).setColor(this->colors.at(randomize(0, this->colors.size() - 1, i)));
                this->numbers.at(i).randomizeDigit();
                coord.X = this->numbers.at(i).getX();
            }
            catch (std::out_of_range const& e) {
                std::cout << " Exception: " << e.what() << std::endl;
            }
            SetConsoleCursorPosition(hConsole, coord);
            SetConsoleTextAttribute(hConsole, this->numbers.at(i).getColor());
            std::cout << this->numbers.at(i);
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
  

