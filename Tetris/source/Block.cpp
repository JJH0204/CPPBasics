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

// TODO: 블럭이 바닥부터 쌓이게 해보자