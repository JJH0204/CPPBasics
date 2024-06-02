/* 테트리스 구현 프로젝트 */
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

#include "Block.h"
#include "Board.h"

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
    Board Board;
    Block Block;

    // std::cout << Block._x << Block._y << std::endl;
    // std::cout << Board._nCol << Board._nRow << std::endl;

    milliseconds msPerFrame(120); /* 대락 60 FPS에 해당하는 시간 */

    while (true)
    {
        /* 현재 시간 기록 */
        auto frameStart = high_resolution_clock::now();

        clearScreen();
        Block._y += 1;
        Board.print(Block);

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