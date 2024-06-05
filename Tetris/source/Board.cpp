#include "Board.hpp"

Board::Board() : _nRow(10), _nCol(20)
{
    /* 2차원 배열 공간 동적으로 생성(할당) */
    _ppSpace = new int *[_nCol];
    for (int i = 0; i < _nCol; i++)
        *(_ppSpace + i) = new int[_nRow];

    /* 동적 할당한 이차원 배열 전체를 0(false)로 초기화 */
    for (int i = 0; i < _nCol; i++)
        for (int j = 0; j < _nRow; j++)
            _ppSpace[i][j] = false;
}
Board::~Board()
{
    // 메모리 해제
    for (int i = 0; i < _nCol; i++)
    {
        delete[] _ppSpace[i];
    }
    delete[] _ppSpace;
}

void Board::merge(Block &block) const
{
    int x = 0, y = 0;
    int **temp = block.getShape();
    for (int i = block.getPosY(); y <= block.getHeight(); i++)
    {
        for (int j = block.getPosX(); x <= block.getWidth(); j++)
        {
            _ppSpace[i][j] = (_ppSpace[i][j] != temp[y][x]);
            x++;
        }
        y++;
    }
}

void Board::print(Block &block) const
{
    this->merge(block);
    std::cout << "############" << std::endl;
    for (int i = 0; i < _nCol; i++)
    {
        std::cout << "#";
        for (int j = 0; j < _nRow; j++)
        {
            std::cout << ((this->_ppSpace[i][j] == 1) ? "@" : " ");
        }
        std::cout << "#" << std::endl;
    }
    std::cout << "############" << std::endl;
    this->merge(block);
}