#include"character.h"
#include<ostream>
#include<iostream>
int character::noOfChars = 0;

character::character() {
	this->characters = {
		'a' , 'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'
		,'q','r','s','t','u','v','w','x','y','z'
	};
}
character::~character() {

}
void character::randomizeDigit() {
	try {
		this->setCh(this->characters.at(randomize(0, this->characters.size() - 1, noOfChars)));
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	noOfChars++;
}

std::ostream& operator<<(std::ostream& output, const character& d) {
	output << d.getCh();

	return output;
}
