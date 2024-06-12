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
