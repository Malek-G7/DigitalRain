#include"character.h"
#include<ostream>
#include<iostream>
int character::noOfChars = 0;

character::character() {
	this->characters = {
		'h','m','j','q','r','t','u','l'
	};
	try {
		this->setCh(this->characters.at(randomize(0, this->characters.size() - 1, noOfChars)));
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	noOfChars++;
}

void character::setChar(char ch) {
	this->ch = ch;
}

char character::getChar() const {
	return this->ch;
}
std::ostream& operator<<(std::ostream& output, const character& d) {
	output << d.getChar();

	return output;
}
