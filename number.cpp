#include"number.h"
#include<ostream>
#include <iostream>
int number::noOfNum = 0;
number::number() {
	this->numbers = {'1','2','3','4','5','6','7','8','9'};
}

number::~number() {

}
void number::randomizeDigit() {
	try {
		this->setCh(this->numbers.at(randomize(0, this->numbers.size() - 1, noOfNum)));
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	noOfNum++;
}

std::ostream& operator<<(std::ostream& output, const number& d) {
	output << d.getCh();
	return output;
}
