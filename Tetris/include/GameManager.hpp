#pragma once
#include <map>
#include "ObjectManager.hpp"

using namespace obj;

class GameManager
{
private:
    Board _Board;
    std::map<char, Block> _BlockList;
    Block _BlockQueue[2];
    Block &_PlayableBlock = _BlockQueue[0];
    int _Point;

public:
    GameManager() {}
    ~GameManager() {}

    void start();
    bool update();
    bool isGameOver();                                                 /* 게임 종료 조건 검사 */
    void processKeyInput(int key, Block &playableBlock, Board &board); /* 키 입력에 따라 지정된 동작을 수행 */

    void setPoint(int nPoint) { this->_Point = nPoint; }
    int getPoint(void) { return this->_Point; }
};
