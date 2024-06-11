#include <iostream>
#include "Block.hpp"

Block::Block() : _width(4), _height(4), _shape(4, std::vector<int>(4, 0))
{
}

Block::~Block() {}

void Block::setShape(BlockType type, const std::vector<std::vector<int>> &sourceShape)
{
    _type = type;
    _shape = sourceShape;
}

void Block::print() const
{
    std::cout << blockTypeNames[_type] << std::endl;

    for (const auto &cols : _shape)
    {
        for (int elem : cols)
            std::cout << ((elem == 1) ? "@" : " ");
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// TODO: 2. 보드에 올려서 보드와 함께 출력하자