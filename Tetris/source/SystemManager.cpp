#include "SystemManager.hpp"

int SystemManager::intRandom06()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, 6);

    return dis(gen);
}

void SystemManager::flushInputBuffer()
{
    int ch;
    while ((ch = getch()) != ERR)
    {
        // 모든 대기중인 입력을 읽고 무시합니다.
    }
}

void SystemManager::cleanScreen()
{
#ifdef _WIN32
    std::system("cls"); // Windows 시스템에서 화면 클리어
#else
    std::system("clear"); // Unix/Linux/MacOS 시스템에서 화면 클리어
#endif
}

void SystemManager::pause(milliseconds msPerFrame)
{
    /* 현재 시간 기록 */
    auto frameStart = high_resolution_clock::now();
    /* 코드 실행 후 시간 기록 */
    auto frameEnd = high_resolution_clock::now();
    /* 경과 시간 계산 */
    auto elapsedTime = frameEnd - frameStart;
    // 프레임 시간을 유지하기 위해 필요하다면 대기
    if (elapsedTime < msPerFrame)
        std::this_thread::sleep_for(msPerFrame - elapsedTime);
}

std::string SystemManager::cleanLine(const std::string &line)
{
    std::string clean;
    for (char c : line)
    {
        if (!isspace(c))
            clean += c;
    }
    return clean;
}

void SystemManager::loadBlocksFromFile(const std::string &filename, std::map<BlockType, Block> &blockList)
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

std::vector<std::vector<int>> SystemManager::parseShape(const std::string &shapeStr)
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

BlockType SystemManager::charToBlockType(char c)
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
