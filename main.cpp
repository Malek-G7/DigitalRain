#include <random>
#include <iostream>     
#include <windows.h>
#include"digit.h"
#include<vector>
#include"Rain.h"
void TestOutputs()
{
    int i = 0;
    std::vector<WORD> colors = { FOREGROUND_BLUE ,FOREGROUND_GREEN,FOREGROUND_RED};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    digit d(5,5,5,FOREGROUND_BLUE);
    digit d2(6, 6, 6, FOREGROUND_GREEN);
    digit d3(7, 7, 7, FOREGROUND_RED);
    COORD coord; 
    coord.X = d.getX();
    coord.Y = d.getY();
    SetConsoleCursorPosition(hConsole, coord);
    SetConsoleTextAttribute(hConsole, d.getColor());
    std::cout << d.getNumber();
    while (1) {
        static std::default_random_engine e;
        static std::uniform_int_distribution<int> u(0, 9);
        static std::default_random_engine e2;
        static std::uniform_int_distribution<int> u2(0, 50);
        static std::default_random_engine e3;
        static std::uniform_int_distribution<int> u3(0, 50);
        e.seed((unsigned int)time(0));
        e2.seed((unsigned int)time(0));
        e3.seed((unsigned int)time(0));
        d.setNumber(u(e));
        d.setX(u2(e2));
        d.setY(u3(e3));
        if (i < colors.size()-1) {
            i++;
        }
        else {
            i = 0;
        }
        d.setColor(colors.at(i));
        coord.X = d.getX();
        coord.Y = d.getY();
        SetConsoleCursorPosition(hConsole, coord);
        SetConsoleTextAttribute(hConsole, d.getColor());
        std::cout << d.getNumber() << d2.getNumber() << d3.getNumber();
        Sleep(1);
    }
    std::cout << d.getNumber();
}

int main(int argc, wchar_t* argv[])
{

    Rain rain;
    int  i = 0;
    bool j = true;
    while (1) {
        rain.digitalRain(i,j);
        Sleep(50);
        i++;
        j = !j;
        
    }
    return 0;
}
