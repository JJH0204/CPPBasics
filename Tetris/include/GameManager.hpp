#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Board.hpp"
#include "Block.hpp"

class GameManager
{
private:
    Board _Board;
    Block _Block;
    int _GameTime;

public:
    GameManager();
    ~GameManager() {}

    int getGameTime() { return _GameTime; }

    void start();
    void update();
};

#endif