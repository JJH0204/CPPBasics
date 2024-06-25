#pragma once

#include <iostream>
#include <chrono>
#include <random>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <thread>

#ifdef WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include "Block.hpp"

using namespace std::chrono;

class SystemManager
{
public:
    SystemManager() {}
    ~SystemManager() {}

    int intRandom06(void);                                  /* 0~6 사이 임의의 int 값 반환 */
    void flushInputBuffer(void);                            /* 입력 버퍼에 대기 중인 문자 제거 */
    void cleanScreen();                                     /* 화면 청소 함수 */
    void pause(milliseconds msPerFrame);                    /* 프레임 당 로직처리 횟수 제어(시간) */
    std::string cleanLine(const std::string &line);
    void loadBlocksFromFile(const std::string &filename, std::map<BlockType, Block> &blockList);
    std::vector<std::vector<int>> parseShape(const std::string &shapeStr);
    BlockType charToBlockType(char c);
};