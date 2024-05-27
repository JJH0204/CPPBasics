#include <iostream>
#include <ctime>
#include "GameManager.h"
#include "Tetris.h"

void GameManager::WorkOut(void)
{
    while (this->getState() != END)
    {
        clearTerminal();
        std::string Input;
        switch (this->getState())
        {
        case OPEN:
            /* 테트리스 게임 베너 출력 */
            printBanner();

            /* 사용자가 Enter 키를 누를 때까지 대기 */
            do
            {
                std::getline(std::cin, Input);
            } while (!Input.empty());

            /* 사용자가 엔터를 눌렀다. 게임을 준비하자 */
            this->setState(READY);
            break;
        case READY:
            /* 3초 카운드 (실제로는 5초) 후 게임 시작 */
            this->Countdown5();
            this->setState(RUN);
            break;
        case RUN:
            /* 사용자가 게임을 시작했다. 게임 규칙데로 프로세스를 진행하자 */
            /* 게임을 진행할 보드 생성 및 초기화 */
            this->PrintBoard();
            /* 블럭 */

            this->setState(END);
            break;
        }
    }
    std::cout << "is End." << std::endl;
}

void GameManager::Countdown5(void)
{
    time_t StartTime = time(nullptr);
    while (1)
    {
        clearTerminal();
        time_t CurrentTime = time(nullptr);
        if (CurrentTime - StartTime >= 5)
            break;
        else if (CurrentTime - StartTime >= 4)
            std::cout << " ■■■■■ ■■■■■   ■■■   ■■■■■  ■■■■■ \n■        ■    ■   ■  ■    ■   ■   \n ■■■■    ■    ■■■■■  ■■■■■    ■   \n     ■   ■   ■     ■ ■  ■     ■   \n■■■■■    ■   ■     ■ ■   ■    ■ " << std::endl;
        else if ((CurrentTime - StartTime) >= 3)
            std::cout
                << "  ■\n ■■\n  ■\n  ■\n■■■■■" << std::endl;
        else if ((CurrentTime - StartTime) >= 2)
            std::cout << "■■■■■\n    ■\n■■■■■\n■    \n■■■■■" << std::endl;
        else if ((CurrentTime - StartTime) >= 1)
            std::cout << "■■■■■\n    ■\n■■■■\n    ■\n■■■■■" << std::endl;
        else
            std::cout << "■■■■■  ■■■■■    ■■■   ■■■■   ■    ■ \n■    ■ ■       ■   ■  ■   ■   ■  ■  \n■■■■■  ■■■■■   ■■■■■  ■    ■   ■■   \n■  ■   ■      ■     ■ ■   ■     ■   \n■   ■  ■■■■■  ■     ■ ■■■■      ■ " << std::endl;
    }
}

void printBanner(void)
{
    std::cout << "##################################################\n#                                                #\n#           ███████ ███████ ███████              #\n#           ██      ██      ██                   #\n#           ██  ███ █████   ███████              #\n#           ██   ██ ██           ██              #\n#           ███████ ███████ ███████              #\n#                                                #\n#      테트리스 세상에 오신 것을 환영합니다      #\n#                                                #\n#           시작하려면 엔터를 누르세요           #\n#                                                #\n##################################################" << std::endl;
}

void clearTerminal(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void GameManager::PrintBoard(void)
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (this->Board[i][j] == WALL)
                std::cout << "#";
            else if (this->Board[i][j] == FULL)
                std::cout << "@";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}