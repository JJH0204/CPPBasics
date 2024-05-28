#include "Terminal.h"

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

void Terminal::ScanEnter()
{
    std::string Input;
    do
    {
        std::getline(std::cin, Input);
        if (Input.)
        {
            /* code */
        }
        
    } while (!Input.empty());
}