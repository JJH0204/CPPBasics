#ifndef __TERMINAL__
#define __TERMINAL__
#include <iostream>
#include <string>
using namespace std;
class Terminal
{
private:
public:
    void Clear(void);
    void PrintNL(const string &String, int size = 1);
    void Print(const string &String, int size = 1);
    void ScanEnter();
};
#endif