#include <iostream>
#include "Block.hpp"

Block::Block() : _width(4), _height(4), _shape(_height, std::vector<int>(_width, 0))
{
    this->setPosX(0);
    this->setPosY(0);
}

Block::Block(BlockType type, Vector2D vector2, int **shape) : _type(type), _width(4), _height(4)
{
    this->setPosX(vector2.getPosX());
    this->setPosY(vector2.getPosY());
    this->setShape(shape);
}

Block::Block(Block &other) : _type(other.getType()), _width(other.getWidth()), _height(other.getHeight())
{
    this->setPosX(other.getPosX());
    this->setPosY(other.getPosY());
    this->_shape = other.getShape();
}

Block::~Block() {}

void Block::setShape(int **sourceShape)
{
    for (int i = 0; i < this->getHeight(); i++)
        for (int j = 0; j < this->getWidth(); j++)
            _shape[i][j] = sourceShape[i][j];
}

void Block::print() const
{
    std::cout << blockTypeNames[_type] << std::endl;
    for (const auto &cols : _shape)
        for (int elem : cols)
            std::cout << ((elem == 1) ? "@" : " ");
}

// TODO: 1. 블록 객체를 만들어서 화면에 출력하자
// TODO: 2. 보드에 올려서 보드와 함께 출력하자