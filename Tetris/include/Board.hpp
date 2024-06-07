#ifndef __BOARD__
#define __BOARD__

#include <iostream>
#include <vector>
#include "Block.hpp"

class Board
{
private:
    int _nRow; /* 2차원 공간 가로 폭 */
    int _nCol; /* 2차원 공간 세로 폭 */
    std::vector<std::vector<int>> _space;   /* 2차원 게임 공간 */

public:
    Board();
    ~Board();

    int getRow() { return _nRow; }
    int getCol() { return _nCol; }

    void setRow(int Row) { _nRow = Row; }
    void setCol(int Col) { _nCol = Col; }

    void merge(Block &block) const;
    void print(/*Block &block*/) const;
};
#endif