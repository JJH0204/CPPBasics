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
    _Board.display(_BlockList[0]);
    _Board.print();
    _Board.refresh(_BlockList[0]);
    _BlockList[0].gravity(1);
}

bool GameManager::isCollision(Vector2D<int> dir, Block obj, Board &spc)
{
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
            }
            
        }
        
    }
    
    
    // 2. 블럭이 공간에 배치된 다른 블럭과 중첩되는지 확인해본다.
    // 3. 블럭이 공간 밖으로 나가는지 확인해본다.
    /* 모든 검사에 무사히 통과했다면 false, 실패했다면 true */
}