#pragma once
#include<string>
#include<Windows.h>
class digit
{
public:
	digit();
	digit(int, int, WORD);
	~digit();
	WORD getColor() const { return color; };
	int getX() const { return x; };
	int getY() const { return y; };
	void setColor(WORD);
	void setCh(char);
	char getCh()const { return ch; };
	void setX(int);
	void setY(int);
	int randomize(int start, int end, int i);
	void randomizeDigit();
private:
	char ch;
	int x;
	int y;
	WORD color;
};

std::ostream& operator<<(std::ostream& output, const digit&);

