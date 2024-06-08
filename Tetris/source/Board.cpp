#include "Board.hpp"

Board::Board() : _nRow(10), _nCol(20), _space(_nCol, std::vector<int>(_nRow, 0)) {}
Board::~Board() {}

// void Board::merge(Block &block) const {}

void Board::print() const
{
    std::cout << "############" << std::endl;
    for (const auto &cols : _space)
    {
        std::cout << "#";

        for (int elem : cols)
            std::cout << ((elem == 1) ? "@" : " ");

        std::cout << "#" << std::endl;
    }
    std::cout << "############" << std::endl;
}