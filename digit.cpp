#include "digit.h"
#include<ostream>

digit::digit() {
	this->x = 0;
	this->y = 0;
	this->number = 0;
	this->color = FOREGROUND_INTENSITY;
}
digit::digit(int x, int y , int number, WORD color) {
	this->x = x;
	this->y = y;
	this->number = number;
	this->color = color;
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
void digit::setNumber(int number) {
	this->number = number;
}
void digit::setCh(char ch) {
	this->ch = ch;
}
std::ostream& operator<<(std::ostream& output, const digit& d) {
	output << d.getCh();
	
	return output;
}
