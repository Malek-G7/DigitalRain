#include"number.h"
#include<ostream>
#include <iostream>
int number::noOfNum = 0;
number::number() {
	this->numbers = {'1','2','3','4','5','6','7','8','9'};
	try {
		this->setCh(this->numbers.at(randomize(0, this->numbers.size() - 1, noOfNum)));
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	noOfNum++;
}

void number::setNum(char num) {
	this->num = num;
}

char number::getNum() const {
	return this->num;
}
std::ostream& operator<<(std::ostream& output, const number& d) {
	output << d.getNum();
	return output;
}
