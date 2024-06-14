/* 테트리스 구현 프로젝트 */
#include <cstdlib>
#include <thread>

#include "GameManager.hpp"

void clearScreen()
{
#ifdef _WIN32
    std::system("cls"); // Windows 시스템에서 화면 클리어
#else
    std::system("clear"); // Unix/Linux/MacOS 시스템에서 화면 클리어
#endif
}

using namespace std::chrono;

void systemPause(milliseconds msPerFrame)
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

int main(int argc, char *argv[])
{
    /* 게임 관리자 객체 생성 */
    GameManager _GameManger;
    /* 게임 데이터 초기화 */
    _GameManger.start();
    
    while (true)
    {
        /* 스크린 초기화 */
        clearScreen();
        /* 게임 진행 */
        if (_GameManger.update())
            break;
        /* 루프 속도 제어 */
        systemPause(milliseconds(_GameManger.getGameTime()));
    }
    return 0;
}

