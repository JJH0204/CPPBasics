#ifndef __BOARD__
#define __BOARD__

#include <iostream>
#include "Block.hpp"

class Board
{
private:
    int _nRow; /* 2차원 공간 가로 폭 */
    int _nCol; /* 2차원 공간 세로 폭 */
    bool **_ppSpace;

public:
    Board() : _nRow(10), _nCol(20)
    {
        /* 2차원 배열 공간 동적으로 생성(할당) */
        _ppSpace = new bool *[_nCol];
        for (int i = 0; i < _nCol; i++)
            *(_ppSpace + i) = new bool[_nRow];

        /* 동적 할당한 이차원 배열 전체를 0(false)로 초기화 */
        for (int i = 0; i < _nCol; i++)
            for (int j = 0; j < _nRow; j++)
                _ppSpace[i][j] = false;
    }
    ~Board()
    {
        // 메모리 해제
        for (int i = 0; i < _nCol; i++)
        {
            delete[] _ppSpace[i];
        }
        delete[] _ppSpace;
    }

    int getRow() { return _nRow; }
    int getCol() { return _nCol; }

    void setRow(int Row) { _nRow = Row; }
    void setCol(int Col) { _nCol = Col; }

    void print(Block &block) const;
};

void Board::print(Block &block) const
{
    std::cout << "############" << std::endl;
    for (int i = 0; i < _nCol; i++)
    {
        std::cout << "#";
        for (int j = 0; j < _nRow; j++)
        {
            if (i == block.getPosY() && j == block.getPosX())
                std::cout << "@";
            else
                std::cout << " ";
        }
        std::cout << "#" << std::endl;
    }
    std::cout << "############" << std::endl;
}
#endif