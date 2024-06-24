#include <iostream>
#include <chrono>
#include <random>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>

#ifdef WIN32
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
    std::map<BlockType, Block> _BlockList;
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
    void processKeyInput(int key, Block &playableBlock, Board &board);
    bool isGameOver();
    void loadBlocksFromFile(const std::string &filename, std::map<BlockType, Block> &blockList);
    std::vector<std::vector<int>> parseShape(const std::string &shapeStr);
    BlockType charToBlockType(char c);
    // void keyInput();
};

#endif