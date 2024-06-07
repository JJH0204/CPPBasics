#include <iostream>
#include "Block.hpp"

Block::Block() : _width(4), _height(4), _shape(_height, std::vector<int>(_width, 0))
{
    this->setPosX(0);
    this->setPosY(0);
}
Block::Block(int x, int y) : _width(4), _height(4), _shape(_height, std::vector<int>(_width, 0))
{
    this->setPosX(x);
    this->setPosY(y);
}
Block::Block(Vector2D val) : _width(4), _height(4), _shape(_height, std::vector<int>(_width, 0))
{
    this->setPosX(val.getPosX());
    this->setPosY(val.getPosY());
}

Block::~Block() {}

void Block::copyShape(const int **sourceShape)
{
    for (int i = 0; i < this->getHeight(); i++)
        for (int j = 0; j < this->getWidth(); j++)
            _shape[i][j] = sourceShape[i][j];
}

void Block::print() const
{
    for (int i = 0; i < this->_height; i++)
        for (int j = 0; j < this->_width; j++)
            std::cout << ((_shape[i][j] == 1) ? "@" : " ");
}

// TODO: 1. 블록 객체를 만들어서 화면에 출력하자
// TODO: 2. 보드에 올려서 보드와 함께 출력하자