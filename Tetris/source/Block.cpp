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

std::vector<std::vector<int>> Block::rotate()
{
    std::vector<std::vector<int>> rotateBlock(4, std::vector<int>(4, 0));

    // 1. 블럭을 90도 회전
    for (int i = 0; i < this->getHeight(); i++)
        for (int j = 0; j < this->getWidth(); j++)
            rotateBlock[j][this->getHeight() - 1 - i] = _shape[i][j];

    // 2. 회전한 블록에 빈 공간 제거
    for (int nCheck = 0; nCheck == 0;)
    {
        for (int i = 0; i < this->getWidth(); i++)
            nCheck += rotateBlock[0][i];
        if (nCheck == 0)
        {
            for (int i = 0; i < this->getHeight() - 1; i++)
                for (int j = 0; j < this->getWidth(); j++)
                    rotateBlock[i][j] = rotateBlock[i + 1][j];

            for (int i = 0; i < this->getWidth(); i++)
                rotateBlock[3][i] = 0;
        }
    }

    for (int nCheck = 0; nCheck == 0;)
    {
        for (int i = 0; i < this->getHeight(); i++)
            nCheck += rotateBlock[i][0];
        if (nCheck == 0)
        {
            for (int j = 0; j < this->getWidth() - 1; j++)
                for (int i = 0; i < this->getHeight(); i++)
                    rotateBlock[i][j] = rotateBlock[i][j + 1];

            for (int i = 0; i < this->getHeight(); i++)
                rotateBlock[i][3] = 0;
        }
    }

    // 3. 기존 모양에 대입
    // 회전 블록 반환
    std::swap(_width, _height);
    return rotateBlock;
}