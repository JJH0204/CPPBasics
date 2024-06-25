#pragma once
#include "SystemManager.hpp"

class GameManager
{
private:
    Board _Board;
    std::map<BlockType, Block> _BlockList;
    Block _BlockQueue[2];
    Block &_PlayableBlock = _BlockQueue[0];

public:
    GameManager() {}
    ~GameManager() {}

    void start();
    bool update();
    bool isGameOver();                                                 /* 게임 종료 조건 검사 */
    void processKeyInput(int key, Block &playableBlock, Board &board); /* 키 입력에 따라 지정된 동작을 수행 */
};
