#include <ctime>
#include "Terminal.h"
#include "Board.h"

#ifndef __TETRIS__
#define __TETRIS__

class Tetris
{
private:
    Board _Board;

public:
    Tetris() {}
    Board *getBoard(void) { return &_Board; }

    void Start();
    void Update();
    

    bool isOver();
    void Print();
};

#endif