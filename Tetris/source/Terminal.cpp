#include "Terminal.h"
#include <conio.h>
#include <iostream>
#include <string>

void Terminal::Clear(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Terminal::PrintNL(const string &String, int size)
{
    Print(String, size);
    cout << endl;
}

void Terminal::Print(const string &String, int size)
{
    for (int i = 0; i < size; i++)
        cout << String[i];
}

KeyCode Terminal::ScanKey()
{
    if (_kbhit())
    {
        int ch = _getch();
        switch (ch)
        {
        case 27:
            return ESC;
            break;
        case 13:
            return ENTER;
            break;
        case 72:
            return UP;
            break;
        case 80:
            return DOWN;
            break;
        case 75:
            return LEFT;
            break;
        case 77:
            return RIGHT;
            break;
        }
    }
}