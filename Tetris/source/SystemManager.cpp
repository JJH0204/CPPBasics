#include <iostream>
#include <chrono>
#include <random> /* 임의의 난수 생성을 위한 라이브러리 */
// #include <string>
// #include <map>
// #include <vector>
#include <fstream>
// #include <sstream>
// #include <cstdlib>
#include <thread>

#include <ncurses.h> /* 터미널 제어용 외부 라이브러리 */

// #include "Block.hpp"
// #include "Board.hpp"

#include "SystemManager.hpp"

using namespace std::chrono;
using namespace obj;

void SystemManager::setTerminal(void)
{
    initscr();             // ncurses 모드 시작
    cbreak();              // 버퍼링 없이 즉시 입력 받음
    noecho();              // 입력한 키를 화면에 표시하지 않음
    keypad(stdscr, TRUE);  // 특수 키 활성화
    nodelay(stdscr, TRUE); // getch()가 블로킹 되지 않도록 설정
}

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

int SystemManager::loadBlocksFromFile(const std::string &filename, std::map<char, Block> &blockList)
{
    /* 지정된 경로의 파일 열기 */
    std::ifstream file(filename);

    /* 제데로 열였는지 확인 */
    if (!file.is_open())
    {
        std::cerr << "파일을 여는데 실패했습니다." << filename << std::endl;
        return 1;               // error code 1
    }

    std::string line;
    while (std::getline(file, line))
    {
        line = cleanLine(line);
        if (line.empty())
            continue;
        char blockType = line[0];
        std::string shapeStr = line.substr(2);
        blockList[blockType].setShape(parseShape(shapeStr));
    }
}

std::vector<std::vector<int>> SystemManager::parseShape(const std::string &shapeStr)
{
    std::cout << shapeStr << std::endl;
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

