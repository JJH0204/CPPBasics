#include "GameManager.hpp"

GameManager::GameManager(void) : _GameTime(200) {}

void GameManager::start(void)
{
    _Block[I].setShape(I, std::vector<std::vector<int>>({{1, 1, 1, 1},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
    _Block[Z].setShape(Z, std::vector<std::vector<int>>({{1, 1, 0, 0},
                                                         {0, 1, 1, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
    _Block[O].setShape(O, std::vector<std::vector<int>>({{1, 1, 0, 0},
                                                         {1, 1, 0, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
    _Block[S].setShape(S, std::vector<std::vector<int>>({{0, 1, 1, 0},
                                                         {1, 1, 0, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
    _Block[J].setShape(J, std::vector<std::vector<int>>({{1, 1, 1, 0},
                                                         {0, 0, 1, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
    _Block[L].setShape(L, std::vector<std::vector<int>>({{1, 1, 1, 0},
                                                         {1, 0, 0, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
    _Block[T].setShape(T, std::vector<std::vector<int>>({{1, 1, 1, 0},
                                                         {0, 1, 0, 0},
                                                         {0, 0, 0, 0},
                                                         {0, 0, 0, 0}}));
}

void GameManager::update(void)
{
    /* 게임 구동 */

    // _Block.gravity(1);
    _Block[I].print();
    _Block[O].print();
    _Block[T].print();
    _Block[S].print();
    _Block[Z].print();
    _Block[J].print();
    _Block[L].print();
    // _Board.print();
}
