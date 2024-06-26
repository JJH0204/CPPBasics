#include <iostream>
#include <ncurses.h>

#include "SystemManager.hpp"
#include "GameManager.hpp"

using namespace obj;

void GameManager::start(void)
{
    SysManager::loadBlocksFromFile("/Users/admin/Documents/GitHub/CPPBasics/Tetris/Data/BlockData.txt", _BlockList);

    // 대기열 초기화
    for (int i = 0; i < 2; i++)
    {
        const char index = blockTypeNames[SysManager::intRandom06()];
        if (_BlockList.find(index) != _BlockList.end())
        {
            _BlockQueue[i] = _BlockList[index];
        }
        else
        {
            std::cerr << "Error: Block type not found in BlockList" << std::endl;
        }
    }

    SysManager::setTerminal();

    this->setPoint(0);
}

bool GameManager::update(void)
{
    /* 게임 구동 */
    // 키를 입력 받고 처리
    int ch = getch();
    processKeyInput(ch, _PlayableBlock, _Board);

    // 블럭이 바닥 또는 다른 블럭에 닿지 않았다.
    if (!_PlayableBlock.isCollision(Vector2D(0, 1), _Board))
    {
        _PlayableBlock.gravity(1);
    }
    // 블럭이 바닥 또는 다른 블럭에 닿았다
    else
    {
        _Board.display(_PlayableBlock);
        _BlockQueue[0] = _BlockQueue[1];
        _BlockQueue[1] = _BlockList[blockTypeNames[SysManager::intRandom06()]];
    }

    /* 점수 획득 여부 확인 */
    while(_Board._flush())
        this->setPoint(this->getPoint() + 1);

    // std::cout << "현재 점수 : " << this->getPoint();     // 게임 UI 하단에 점수도 같이 출력하고 싶은데 이 방법은 아닌 것 같다.
    
    /* 게임 종료 여부 체크 */
    bool isOver = isGameOver();
    
    _Board.display(_PlayableBlock);
    _Board.print();
    _Board._refresh(_PlayableBlock);
    return isOver;
}

bool GameManager::isGameOver()
{
    if (_PlayableBlock.isCollision(Vector2D(0, 0), _Board) == false)
        return false;
    return true;
}

// 회전 시 블럭 또는 벽을 무시해 뚫고 지나가거나 걸리는 버그 발생
// 1. 블록 회전 전에 블록 충돌 여부를 확인하는 코드에 문제가 있는지 확인한다.
void GameManager::processKeyInput(int key, Block &playableBlock, Board &board)
{
    // <-, -> 로 블럭 이동
    // space 로 블럭 회전
    Vector2D movement = Vector2D(0, 0);
    bool shouldUpdate = false;

    switch (key)
    {
    case KEY_UP:
        // 특정 키에 대한 처리 로직
        break;
    case KEY_DOWN:
        movement = Vector2D(0, 1);
        break;
    case KEY_LEFT:
        movement = Vector2D(-1, 0);
        break;
    case KEY_RIGHT:
        movement = Vector2D(1, 0);
        break;
    case ' ': // Space bar
        Block tempBlock = Block(playableBlock.rotate(), playableBlock.getPos());
        if (!tempBlock.isCollision(Vector2D(0, 0), board))
        {
            playableBlock.setShape(tempBlock.getShape());
            shouldUpdate = true;
        }
        break;
    }

    if (movement.getPosX() != 0 || movement.getPosY() != 0)
    {
        if (!playableBlock.isCollision(movement, board))
        {
            playableBlock.move(movement);
            shouldUpdate = true;
        }
    }

    if (shouldUpdate)
    {
        board.display(playableBlock);
        board.print();
        board._refresh(playableBlock);
    }

    SysManager::flushInputBuffer(); // 모든 입력 후에 한 번만 버퍼를 플러시
}