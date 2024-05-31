#ifndef __TERMINAL__
#define __TERMINAL__

using namespace std;
enum KeyCode
{
    ESC,
    ENTER,
    LEFT,
    RIGHT,
    DOWN,
    UP
};

class Terminal
{
private:
public:
    void Clear(void);
    void PrintNL(const string &String, int size = 1);
    void Print(const string &String, int size = 1);
    KeyCode ScanKey();
};
#endif