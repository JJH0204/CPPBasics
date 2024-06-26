/* 테트리스 구현 프로젝트 */
#include <ncurses.h>
#include <chrono>

#include "GameManager.hpp"
#include "SystemManager.hpp"

using namespace std::chrono;

int main(int argc, char *argv[])
{
    /* 게임 관리자 객체 생성 */
    GameManager _GameManger;
    /* 게임 데이터 초기화 */
    _GameManger.start();
    refresh();
    while (true)
    {
        /* 스크린 초기화 */
        SystemManager().cleanScreen();
        /* 게임 진행 */
        if (_GameManger.update())
            break;
        /* 루프 속도 제어 */
        SystemManager().pause(milliseconds(200));
    }
    endwin();   // 터미널 설정을 원래대로 복구
    return 0;
}

