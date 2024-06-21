#include "Board.hpp"
// #include "Block.hpp"

Board::Board() : _nRow(10), _nCol(20), _space(_nCol, std::vector<int>(_nRow, 0)) {}
Board::~Board() {}

// void Board::merge(Block &block) const {}

void Board::print() const
{
    std::cout << "############" << std::endl;
    for (auto &cols : _space)
    {
        std::cout << "#";

        for (int elem : cols)
            std::cout << ((elem == 1) ? "@" : " ");

        std::cout << "#" << std::endl;
    }
    std::cout << "############" << std::endl;
}

void Board::display(Block block)
{
    int x = block.getPosX();
    int y = block.getPosY();

    for (int i = 0; i < block.getHeight(); i++)
    {
        for (int j = 0; j < block.getWidth(); j++)
        {
            if ((block.getShape()[i][j] > 0))
            {
                _space[i + y][j + x] = block.getShape()[i][j];
            }
        }
    }
}

void Board::refresh(Block block)
{
    int x = block.getPosX();
    int y = block.getPosY();

    for (int i = 0; i < block.getHeight(); i++)
    {
        for (int j = 0; j < block.getWidth(); j++)
        {
            if ((block.getShape()[i][j] > 0) && (block.getShape()[i][j] == _space[i + y][j + x]))
            {
                _space[i + y][j + x] = 0;
            }
        }
    }
}

