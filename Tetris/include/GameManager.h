/* 테트리스 게임 관리자 객체 */
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__

#include "Tetris.h"

enum GameState
{
    OPEN,
    READY,
    RUN,
    END
};
class GameManager
{
private:
    int _State;
    Tetris _Tetris;

public:
    GameManager() { setState(OPEN); }
    ~GameManager() {}

    void setState(int state) { _State = state; }
    int getState(void) { return _State; }
    Tetris *getTetris(void) { return &_Tetris; }

    void Opening();
    void Countdown_5();
    void Ending();

    void WorkOut(void);
    // void GameReset();       /* 객체 생성 및 재시작 선택 시 실행 */
    // void GameRun();         /* 게임 실행 */
    // void GameSaveData();    /* 게임 종료 후 점수 기록 저장 */
    // void GameEnd();         /* 게임 종료 */
};

#endif