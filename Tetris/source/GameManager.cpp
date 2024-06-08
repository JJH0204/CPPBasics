#include "GameManager.hpp"

GameManager::GameManager(void) : _GameTime(200) {}

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
    // _Block.setShape(new int *[4]{
    //     new int[4]{1, 1, 1, 1},
    //     new int[4]{0, 0, 0, 0},
    //     new int[4]{0, 0, 0, 0},
    //     new int[4]{0, 0, 0, 0}});
    _Block = Block(I, Vector2D(0, 0), new int *[4]{
        new int[4]{1, 1, 1, 1}, 
        new int[4]{0, 0, 0, 0}, 
        new int[4]{0, 0, 0, 0}, 
        new int[4]{0, 0, 0, 0}});
    _Block.print();
    // _Board.print();
}

// 블록을 복사 생성하는 중에 프로그램이 종료되는지 출력 중에 종료되는지 확인해보자