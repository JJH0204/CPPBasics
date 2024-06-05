/* 테트리스 구현 프로젝트 */
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Block.hpp"
#include "Board.hpp"

void clearScreen()
{
#ifdef _WIN32
    std::system("cls"); // Windows 시스템에서 화면 클리어
#else
    std::system("clear"); // Unix/Linux/MacOS 시스템에서 화면 클리어
#endif
}

using namespace std::chrono;

int main(int argc, char *argv[])
{
    Board _Board;
    Block _Block;

    /* 게임 설정 */
    const bool temp[4][4] = {{1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    _Block = Block(I, 4, 4, temp);

    milliseconds msPerFrame(200); /* 게임 속도 제어 */

    while (true)
    {
        /* 현재 시간 기록 */
        auto frameStart = high_resolution_clock::now();

        clearScreen();

        /* 게임 구동 */

        _Block.gravity(1);
        _Board.print(_Block);

        /* 코드 실행 후 시간 기록 */
        auto frameEnd = high_resolution_clock::now();
        /* 경과 시간 계산 */
        auto elapsedTime = frameEnd - frameStart;

        // 프레임 시간을 유지하기 위해 필요하다면 대기
        if (elapsedTime < msPerFrame)
            std::this_thread::sleep_for(msPerFrame - elapsedTime);
    }
    return 0;
}