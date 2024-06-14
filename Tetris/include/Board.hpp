#ifndef __BOARD__
#define __BOARD__

#include <iostream>
#include <vector>
#include "Block.hpp"

class Board
{
private:
    int _nRow, _nCol;                     /* 2차원 공간 가로, 세로 폭 */
    std::vector<std::vector<int>> _space; /* 2차원 게임 공간 */

public:
    Board();
    ~Board();

    int getRow() { return _nRow; }
    int getCol() { return _nCol; }
    std::vector<std::vector<int>> getSpace() { return _space; }

    void setRow(int Row) { _nRow = Row; }
    void setCol(int Col) { _nCol = Col; }

    // void merge(Block &block) const;
    void print() const;
    void display(Block block);
    void refresh(Block block);

    bool isFullOfCols();
};
#endif