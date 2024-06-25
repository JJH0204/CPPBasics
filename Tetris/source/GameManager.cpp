#include "GameManager.hpp"

void GameManager::start(void)
{
    SystemManager().loadBlocksFromFile("Data/BlockData.txt", _BlockList);

    // 대기열 초기화
    for (int i = 0; i < 2; i++)
    {
        BlockType type = static_cast<BlockType>(SystemManager().intRandom06());
        if (_BlockList.find(type) != _BlockList.end())
        {
            _BlockQueue[i] = _BlockList[type];
        }
        else
        {
            std::cerr << "Error: Block type not found in BlockList" << std::endl;
        }
    }

    initscr();             // ncurses 모드 시작
    cbreak();              // 버퍼링 없이 즉시 입력 받음
    noecho();              // 입력한 키를 화면에 표시하지 않음
    keypad(stdscr, TRUE);  // 특수 키 활성화
    nodelay(stdscr, TRUE); // getch()가 블로킹 되지 않도록 설정
}

bool GameManager::update(void)
{
    /* 게임 구동 */
    // 키를 입력 받고 처리
    int ch = getch();
    processKeyInput(ch, _PlayableBlock, _Board);

    // 블럭이 바닥 또는 다른 블럭에 닿지 않았다.
    if (_PlayableBlock.isCollision(Vector2D(0, 1), _Board) == false)
    {
        _PlayableBlock.gravity(1);
    }
    // 블럭이 바닥 또는 다른 블럭에 닿았다
    else
    {
        _Board.display(_PlayableBlock);
        _BlockQueue[0] = _BlockQueue[1];
        _BlockQueue[1] = _BlockList[static_cast<BlockType>(SystemManager().intRandom06())];
    }

    /* 게임 종료 여부 체크 */
    bool isOver = isGameOver();
    return isOver;
}

bool GameManager::isGameOver()
{
    if (_PlayableBlock.isCollision(Vector2D(0, 0), _Board) == false)
    {
        _Board.display(_PlayableBlock);
        _Board.print();
        _Board._refresh(_PlayableBlock);
        return false;
    }
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
        if (!Block(playableBlock.rotate(), playableBlock.getPos()).isCollision(Vector2D(0, 0), board))
        {
            playableBlock.setShape(playableBlock.getType(), playableBlock.rotate());
            shouldUpdate = true;
        }
        break;
    case 27: // ESC key
        // Escape key logic
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

    SystemManager().flushInputBuffer(); // 모든 입력 후에 한 번만 버퍼를 플러시
}