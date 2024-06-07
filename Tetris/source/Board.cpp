#include "Board.hpp"

Board::Board() : _nRow(10), _nCol(20), _space(_nRow, std::vector<int>(_nCol, 0))
{
    // /* 2차원 배열 공간 동적으로 생성(할당) */
    // _space.resize(_nCol, std::vector<int>(_nRow)); /* 이차원 배열 리사이징 */

    // for (int i = 0; i < this->getCol(); i++)
    //     for (int j = 0; j < this->getRow(); j++)
    //         _space[i][j] = 0;
}
Board::~Board()
{
    // 메모리 해제
    // for (int i = 0; i < _nCol; i++)
    // {
    //     delete[] _space[i];
    // }
    // delete[] _space;
}

void Board::merge(Block &block) const
{
    // int x = 0, y = 0;
    // int **temp = block.getShape();
    // for (int i = block.getPosY(); y <= block.getHeight(); i++)
    // {
    //     for (int j = block.getPosX(); x <= block.getWidth(); j++)
    //     {
    //         _space[i][j] = (_space[i][j] != temp[y][x]);
    //         x++;
    //         /* code */
    //     }
    //     y++;
    // }
}

void Board::print() const
{
    std::cout << "############" << std::endl;
    for (const auto &cols : _space)
    {
        std::cout << "#";

        for (int elem : cols)
            std::cout << ((elem == 1) ? "@" : "%");

        std::cout << "#" << std::endl;
    }
    std::cout << "############" << std::endl;
}