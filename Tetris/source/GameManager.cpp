#include "GameManager.hpp"

GameManager::GameManager(void) : _GameTime(200) {}

int random_0_6()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, 6);

    return dis(gen);
}

void GameManager::start(void)
{
    _BlockList[I].setShape(I, std::vector<std::vector<int>>({{1, 1, 1, 1},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));
    _BlockList[Z].setShape(Z, std::vector<std::vector<int>>({{1, 1, 0, 0},
                                                             {0, 1, 1, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));
    _BlockList[O].setShape(O, std::vector<std::vector<int>>({{1, 1, 0, 0},
                                                             {1, 1, 0, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));
    _BlockList[S].setShape(S, std::vector<std::vector<int>>({{0, 1, 1, 0},
                                                             {1, 1, 0, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));
    _BlockList[J].setShape(J, std::vector<std::vector<int>>({{1, 1, 1, 0},
                                                             {0, 0, 1, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));
    _BlockList[L].setShape(L, std::vector<std::vector<int>>({{1, 1, 1, 0},
                                                             {1, 0, 0, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));
    _BlockList[T].setShape(T, std::vector<std::vector<int>>({{1, 1, 1, 0},
                                                             {0, 1, 0, 0},
                                                             {0, 0, 0, 0},
                                                             {0, 0, 0, 0}}));

    // 대기열 초기화
    for (int i = 0; i < 2; i++)
        _BlockQueue[i] = _BlockList[random_0_6()];
}

bool GameManager::update(void)
{
    /* 게임 구동 */
    if (isCollision(Vector2D(0, 0), _PlayableBlock, _Board) == false)
        _Board.display(_PlayableBlock);
    else
        return true;
    _Board.print();
    _Board.refresh(_PlayableBlock);

    // 키를 입력 받고
    // <-, -> 로 블럭 이동
    // space 로 블럭 회전
    
    // 블럭이 바닥 또는 다른 블럭에 닿지 않았다.
    if (isCollision(Vector2D(0, 1), _PlayableBlock, _Board) == false)
    {
        _PlayableBlock.gravity(1);
    }
    // 블럭이 바닥 또는 다른 블럭에 닿았다
    else
    {
        _Board.display(_PlayableBlock);
        _BlockQueue[0] = _BlockQueue[1];
        _BlockQueue[1] = _BlockList[random_0_6()];
    }
    return false;
}

bool GameManager::isCollision(Vector2D<int> dir, Block obj, Board &spc)
{
    // std::cout << spc.getRow() << spc.getCol() << std::endl;
    // 1. 이동 방향으로 블럭의 복사본을 공간 복사본으로 이동 시킨다.
    obj.setPosX(obj.getPosX() + dir.getPosX());
    obj.setPosY(obj.getPosY() + dir.getPosY());

    for (int i = 0; i < obj.getHeight(); i++)
    {
        for (int j = 0; j < obj.getWidth(); j++)
        {
            if (obj.getShape()[i][j] == 1)
            {
                // 블럭이 벽에 충돌되었는지 바닥에 충돌되었는지 다른 블럭과 출돌되었는지 확인하면 됨
                // std::cout << spc.getRow() << spc.getCol() << std::endl;
                if ((obj.getPosY() + i) >= spc.getCol() || (obj.getPosY() + i) < 0)
                {
                    // std::cout << "case 1" << std::endl;
                    return true;
                }

                if ((obj.getPosX() + j) >= spc.getRow() || (obj.getPosX() + j) < 0)
                {
                    // std::cout << "case 2" << std::endl;
                    return true;
                }

                if (spc.getSpace()[obj.getPosY() + i][obj.getPosX() + j] == 1)
                {
                    // std::cout << "case 3" << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void GameManager::keyInput()
{
    // int ch = getch()
}