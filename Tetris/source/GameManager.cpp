#include "GameManager.hpp"

GameManager::GameManager(void)
{
    /* code */
}

void GameManager::start(void)
{
    /* 게임 설정 */
    // const int temp[][4] = {{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    // _Block = Block(I, temp);
}

void GameManager::update(void)
{
    /* 게임 구동 */

    // _Block.gravity(1);
    _Block.print();
    // _Board.print(_Block);
}