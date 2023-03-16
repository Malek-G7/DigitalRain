#pragma once
#include<string>
#include<Windows.h>
class digit
{
public:
	digit();
	digit(int, int,int, WORD);
	WORD getColor() const { return color; };
	int getX() const { return x; };
	int getY() const { return y; };
	int getNumber() const { return number; };
	void setNumber(int);
	void setColor(WORD);
	void setCh(char);
	char getCh()const { return ch; };
	void setX(int);
	void setY(int);
	int randomizeXY(int);
private:
	int number;
	char ch;
	int x;
	int y;
	WORD color;
};

std::ostream& operator<<(std::ostream& output, const digit&);

