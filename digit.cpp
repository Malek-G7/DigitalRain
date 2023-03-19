#include "digit.h"
#include<ostream>
#include <random>

#include <iostream>
digit::digit() {
	this->x = 0;
	this->y = 0;
	this->color = FOREGROUND_INTENSITY ;
	this->ch = '1' ;
}
digit::digit(int x, int y ,  WORD color) {
	this->x = x;
	this->y = y;
	this->color = color;
}
digit::~digit() {

}

void digit::setColor(WORD color) {
	this->color = color;
}
void digit::setX(int x ) {
	this->x = x;
}
void digit::setY(int y) {
	this->y = y;
}
void digit::randomizeDigit() {

}
void digit::setCh(char ch) {
	this->ch = ch;
}

std::ostream& operator<<(std::ostream& output, const digit& d) {
	output << d.getCh();
	
	return output;
}
int digit::randomize(int start, int end, int i) {
	std::default_random_engine e;
	std::uniform_int_distribution<int> u(start, end);
	e.seed((unsigned int)time(0) + i);
	return u(e);
}
