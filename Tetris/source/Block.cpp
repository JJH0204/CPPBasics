#include "Block.hpp"

Block::Block() : _width(4), _height(4), _shape(4, std::vector<int>(4, 0)) {}

Block::Block(std::vector<std::vector<int>> shape, Vector2D pos) : _shape(shape)
{
    this->setPos(pos);
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
    return rotateBlock;
}

bool Block::isCollision(Vector2D<int> dir, auto &spc)
{
    // std::cout << spc.getRow() << spc.getCol() << std::endl;
    // 1. 이동 방향으로 블럭의 복사본을 공간 복사본으로 이동 시킨다.
    // obj.setPosX(obj.getPosX() + dir.getPosX());
    // obj.setPosY(obj.getPosY() + dir.getPosY());
    this->setPos(this->getPos() + dir);

    for (int i = 0; i < this->getHeight(); i++)
    {
        for (int j = 0; j < this->getWidth(); j++)
        {
            if (this->getShape()[i][j] == 1)
            {
                // 블럭이 벽에 충돌되었는지 바닥에 충돌되었는지 다른 블럭과 출돌되었는지 확인하면 됨
                // std::cout << spc.getRow() << spc.getCol() << std::endl;
                if ((this->getPosY() + i) >= spc.getCol() || (this->getPosY() + i) < 0)
                {
                    // std::cout << "case 1" << std::endl;
                    return true;
                }

                if ((this->getPosX() + j) >= spc.getRow() || (this->getPosX() + j) < 0)
                {
                    // std::cout << "case 2" << std::endl;
                    return true;
                }

                if (spc.getSpace()[this->getPosY() + i][this->getPosX() + j] == 1)
                {
                    // std::cout << "case 3" << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}