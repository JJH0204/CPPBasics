#include <iostream>
#include "GameManager.h"

void GameManager::WorkOut(void)
{
    while (this->getState() != END)
    {
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
            std::cout << "is Ready~!" << std::endl;
            /* 화면에 큰 숫자로 3, 2, 1 카운트 다운을 진행해 사용자가 게임 시작전 마음의 준비할 시간을 준다 */
            this->setState(RUN);
            break;
        case RUN:
            std::cout << "is Run!" << std::endl;
            this->setState(END);
            break;
        }
    }
    std::cout << "is End." << std::endl;
}

void printBanner(void)
{
    std::cout << "##################################################\n#                                                #\n#           ███████ ███████ ███████              #\n#           ██      ██      ██                   #\n#           ██  ███ █████   ███████              #\n#           ██   ██ ██           ██              #\n#           ███████ ███████ ███████              #\n#                                                #\n#      테트리스 세상에 오신 것을 환영합니다      #\n#                                                #\n#           시작하려면 엔터를 누르세요           #\n#                                                #\n##################################################" << std::endl;
}