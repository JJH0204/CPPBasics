/* 테트리스 게임 관리자 객체 */
#ifndef __GAMEMANAGER__
#define __GAMEMANAGER__
enum
{
    OPEN,
    READY,
    RUN,
    END
};

class GameManager
{
private:
    int _state;

public:
    GameManager() { setState(OPEN); }
    ~GameManager() {}
    void setState(int state) { _state = state; }
    int getState(void) { return _state; }

    void WorkOut(void);
    // void GameReset();       /* 객체 생성 및 재시작 선택 시 실행 */
    // void GameRun();         /* 게임 실행 */
    // void GameSaveData();    /* 게임 종료 후 점수 기록 저장 */
    // void GameEnd();         /* 게임 종료 */
};

void printBanner(void);

#endif