#include "Terminal.h"
#include "GameManager.h"
#include "Tetris.h"

void GameManager::WorkOut(void)
{
    while (1)
    {
        Terminal().Clear();
        switch (this->getState())
        {
        case OPEN:
            /* 테트리스 게임 베너 출력 */
            this->Opening();

            /* 사용자가 Enter 키를 누를 때까지 대기 */
            do
            {
            } while (Terminal().ScanKey() != ENTER);

            /* 사용자가 엔터를 눌렀다. 게임을 준비하자 */
            this->setState(READY);
            break;

        case READY:
            /* 3초 카운드 (실제로는 5초) 후 게임 시작 */
            this->Countdown_5();
            this->setState(RUN);
            break;

        case RUN:
            /* 사용자가 게임을 시작했다. 게임 규칙데로 프로세스를 진행하자 */
            /* 게임을 진행할 보드 생성 및 초기화 */
            _Tetris.Start();
            while (_Tetris.isOver())
            {
                _Tetris.Update();
                _Tetris.Print();
            }
            this->setState(END);
            break;

        case END:
            this->Ending();
            while (1)
            {
                KeyCode scankey = Terminal().ScanKey();
                if (scankey == ENTER)
                {
                    this->setState(READY);
                    break;
                }
                else if (scankey == ESC)
                    return;
                    
            }
            break;
        }
    }
}

void GameManager::Opening()
{
    Terminal().PrintNL("##################################################\n#                                                #\n#           ███████ ███████ ███████              #\n#           ██      ██      ██                   #\n#           ██  ███ █████   ███████              #\n#           ██   ██ ██           ██              #\n#           ███████ ███████ ███████              #\n#                                                #\n#      테트리스 세상에 오신 것을 환영합니다      #\n#                                                #\n#           시작하려면 엔터를 누르세요           #\n#                                                #\n##################################################\0", 838);
}

void GameManager::Countdown_5()
{
    time_t StartTime = time(nullptr);
    while (1)
    {
        time_t CurrentTime = time(nullptr);
        Terminal().Clear();
        if (CurrentTime - StartTime >= 5)
            break;
        else if (CurrentTime - StartTime >= 4)
            Terminal().PrintNL(" ■■■■■ ■■■■■   ■■■   ■■■■■  ■■■■■ \n■        ■    ■   ■  ■    ■   ■   \n ■■■■    ■    ■■■■■  ■■■■■    ■   \n     ■   ■   ■     ■ ■  ■     ■   \n■■■■■    ■   ■     ■ ■   ■    ■ \0", 302);
        else if ((CurrentTime - StartTime) >= 3)
            Terminal().PrintNL("  ■\n ■■\n  ■\n  ■\n■■■■■\0", 43);
        else if ((CurrentTime - StartTime) >= 2)
            Terminal().PrintNL("■■■■■\n    ■\n■■■■■\n■    \n■■■■■\0", 65);
        else if ((CurrentTime - StartTime) >= 1)
            Terminal().PrintNL("■■■■■\n    ■\n■■■■\n    ■\n■■■■■\0", 62);
        else
            Terminal().PrintNL("■■■■■  ■■■■■    ■■■   ■■■■   ■    ■ \n■    ■ ■       ■   ■  ■   ■   ■  ■  \n■■■■■  ■■■■■   ■■■■■  ■    ■   ■■   \n■  ■   ■      ■     ■ ■   ■     ■   \n■   ■  ■■■■■  ■     ■ ■■■■      ■ \0", 322);
    }
}

void GameManager::Ending()
{
    Terminal().PrintNL("  ■■■■  \n ■    ■ \n■          ■■■   ■    ■ ■■■■■    ■■■  ■     ■ ■■■■■ ■■■■■  \n■   ■■■   ■   ■  ■■  ■■ ■       ■   ■ ■     ■ ■     ■    ■ \n■    ■■   ■■■■■  ■ ■■ ■ ■■■■■   ■   ■  ■   ■  ■■■■■ ■■■■■  \n ■    ■  ■     ■ ■    ■ ■       ■   ■   ■ ■   ■     ■  ■  \n  ■■■■   ■     ■ ■    ■ ■■■■■    ■■■     ■    ■■■■■ ■   ■  ", 555);
    Terminal().PrintNL("------------- 재도전을 위해 엔터를 눌러주세요. -------------", 75);
    Terminal().PrintNL("---------- ESC를 눌러 게임을 종료할 수 있습니다. ----------", 74);
}