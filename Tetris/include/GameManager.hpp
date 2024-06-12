#include "Board.hpp"
#include "Block.hpp"

#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__


class GameManager
{
private:
    Board _Board;
    Block _BlockList[7];
    int _GameTime;

public:
    GameManager();
    ~GameManager() {}

    int getGameTime() { return _GameTime; }

    void start();
    void update();
};

#endif