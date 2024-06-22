#include <iostream>
#include <chrono>
#include <random>
#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "Board.hpp"
#include "Block.hpp"

#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__


class GameManager
{
private:
    Board _Board;
    Block _BlockList[7];
    Block _BlockQueue[2];
    Block &_PlayableBlock = _BlockQueue[0];
    int _GameTime;

public:
    GameManager();
    ~GameManager() {}

    int getGameTime() { return _GameTime; }

    void start();
    bool update();

    bool isCollision(Vector2D<int> dir, Block obj, Board &spc);

    // void keyInput();
};

#endif