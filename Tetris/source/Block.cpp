#include <iostream>
#include "Block.hpp"

Block::Block() : _width(4), _height(4)
{
    this->setPosX(0);
    this->setPosY(0);
    this->allocShape();
}
Block::Block(int x, int y) : _width(4), _height(4)
{
    this->setPosX(x);
    this->setPosY(y);
    this->allocShape();
}
Block::Block(Vector2 val) : _width(4), _height(4)
{
    this->setPosX(val.getPosX());
    this->setPosY(val.getPosY());
    this->allocShape();
}

// Block::Block(const BlockType type, const int ppShape[4][4]) : _type(type), _width(4), _height(4)
// {
//     this->setPosX(0);
//     this->setPosY(0);
//     this->allocShape();
//     for (int i = 0; i < _height; i++)
//         for (int j = 0; j < _width; j++)
//             _ppShape[i][j] = ppShape[i][j];
// }
// // 복사 생성자
// Block::Block(const Block &other) : Vector2<int>(other), _type(other._type), _width(other._width), _height(other._height)
// {
//     this->allocShape();
//     this->copyShape(const_cast<const int **>(other._ppShape)); // 상수성 유지
// }

Block::~Block()
{
    for (int i = 0; i < this->getHeight(); i++)
        delete[] _ppShape[i];
    delete[] _ppShape;
}

void Block::allocShape(void)
{
    _ppShape = new int *[this->getHeight()];
    for (int i = 0; i < this->getHeight(); i++)
        *(_ppShape + i) = new int[this->getWidth()];
}

void Block::copyShape(const int **sourceShape)
{
    for (int i = 0; i < this->getHeight(); i++)
        for (int j = 0; j < this->getWidth(); j++)
            _ppShape[i][j] = sourceShape[i][j];
}

void Block::print() const
{
    for (int i = 0; i < this->_height; i++)
        for (int j = 0; j < this->_width; j++)
            std::cout << ((_ppShape[i][j] == 1) ? "@" : " ");
}