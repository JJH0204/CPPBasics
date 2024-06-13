#include "GameManager.hpp"

GameManager::GameManager(void) : _GameTime(200) {}

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
}

void GameManager::update(void)
{
    /* 게임 구동 */
    int nShape = 1;
    _Board.display(_BlockList[nShape]);
    _Board.print();
    _Board.refresh(_BlockList[nShape]);
    if (isCollision(Vector2D(0, 1), _BlockList[nShape], _Board) == false)
    {
        _BlockList[nShape].gravity(1);
    }
    else
    {
        _Board.display(_BlockList[nShape]);
        _BlockList[nShape].setPos(Vector2D<int>(0, 0));
    }
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
                std::cout << spc.getRow() << spc.getCol() << std::endl;
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
    // 2. 블럭이 공간에 배치된 다른 블럭과 중첩되는지 확인해본다.
    // 3. 블럭이 공간 밖으로 나가는지 확인해본다.
    /* 모든 검사에 무사히 통과했다면 false, 실패했다면 true */
}