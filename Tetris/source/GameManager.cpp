#include "GameManager.hpp"

GameManager::GameManager(void) : _GameTime(200) {}

int random_0_6()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, 6);

    return dis(gen);
}

void flushInputBuffer()
{
    int ch;
    while ((ch = getch()) != ERR)
    {
        // 모든 대기중인 입력을 읽고 무시합니다.
    }
}

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
        if (!isCollision(Vector2D(0, 0), Block(playableBlock.rotate(), playableBlock.getPos()), board))
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
        if (!isCollision(movement, playableBlock, board))
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

    flushInputBuffer(); // 모든 입력 후에 한 번만 버퍼를 플러시
}

bool GameManager::isGameOver()
{
    if (isCollision(Vector2D(0, 0), _PlayableBlock, _Board) == false)
    {
        _Board.display(_PlayableBlock);
        _Board.print();
        _Board._refresh(_PlayableBlock);
        return false;
    }
    return true;
}

void GameManager::start(void)
{
    loadBlocksFromFile("Data/BlockData.txt", _BlockList);

    // 대기열 초기화
    for (int i = 0; i < 2; i++)
    {
        BlockType type = static_cast<BlockType>(random_0_6());
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
    if (isCollision(Vector2D(0, 1), _PlayableBlock, _Board) == false)
    {
        _PlayableBlock.gravity(1);
    }
    // 블럭이 바닥 또는 다른 블럭에 닿았다
    else
    {
        _Board.display(_PlayableBlock);
        _BlockQueue[0] = _BlockQueue[1];
        _BlockQueue[1] = _BlockList[static_cast<BlockType>(random_0_6())];
    }

    /* 게임 종료 여부 체크 */
    bool isOver = isGameOver();
    return isOver;
}

bool GameManager::isCollision(Vector2D<int> dir, Block obj, Board &spc)
{
    // std::cout << spc.getRow() << spc.getCol() << std::endl;
    // 1. 이동 방향으로 블럭의 복사본을 공간 복사본으로 이동 시킨다.
    // obj.setPosX(obj.getPosX() + dir.getPosX());
    // obj.setPosY(obj.getPosY() + dir.getPosY());
    obj.setPos(obj.getPos() + dir);

    for (int i = 0; i < obj.getHeight(); i++)
    {
        for (int j = 0; j < obj.getWidth(); j++)
        {
            if (obj.getShape()[i][j] == 1)
            {
                // 블럭이 벽에 충돌되었는지 바닥에 충돌되었는지 다른 블럭과 출돌되었는지 확인하면 됨
                // std::cout << spc.getRow() << spc.getCol() << std::endl;
                if ((obj.getPosY() + i) >= spc.getCol() || (obj.getPosY() + i) < 0)
                {
                    // std::cout << "case 1" << std::endl;
                    return true;
                }

                if ((obj.getPosX() + j) >= spc.getRow() || (obj.getPosX() + j) < 0)
                {
                    // std::cout << "case 2" << std::endl;
                    return true;
                }

                if (spc.getSpace()[obj.getPosY() + i][obj.getPosX() + j] == 1)
                {
                    // std::cout << "case 3" << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}

// 회전 시 블럭 또는 벽을 무시해 뚫고 지나가거나 걸리는 버그 발생
// 1. 블록 회전 전에 블록 충돌 여부를 확인하는 코드에 문제가 있는지 확인한다.

std::string cleanLine(const std::string &line)
{
    std::string clean;
    for (char c : line)
    {
        if (!isspace(c))
            clean += c;
    }
    return clean;
}

void GameManager::loadBlocksFromFile(const std::string &filename, std::map<BlockType, Block> &blockList)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        line = cleanLine(line);
        if (line.empty())
            continue;
        BlockType blockType = charToBlockType(line[0]);
        std::string shapeStr = line.substr(2);
        blockList[blockType].setShape(blockType, parseShape(shapeStr));
    }
}

std::vector<std::vector<int>> GameManager::parseShape(const std::string &shapeStr)
{
    std::vector<std::vector<int>> shape;
    std::istringstream ss(shapeStr);
    std::string row;

    while (std::getline(ss, row, ';'))
    {
        std::vector<int> rowVector;
        std::istringstream rowStream(row);
        std::string cell;
        while (std::getline(rowStream, cell, ','))
        {
            rowVector.push_back(std::stoi(cell));
        }
        shape.push_back(rowVector);
    }

    return shape;
}

BlockType GameManager::charToBlockType(char c)
{
    switch (c)
    {
    case 'I':
        return BlockType::I;
    case 'O':
        return BlockType::O;
    case 'T':
        return BlockType::T;
    case 'S':
        return BlockType::S;
    case 'Z':
        return BlockType::Z;
    case 'J':
        return BlockType::J;
    case 'L':
        return BlockType::L;
    default:
        throw std::invalid_argument("Invalid block type character");
    }
}

