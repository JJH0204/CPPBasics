#include <iostream>
#include <ncurses.h>
#include "ObjectManager.hpp"

using namespace obj;

Block::Block() : _width(4), _height(4), _shape(4, std::vector<int>(4, 0)) {}

Block::Block(std::vector<std::vector<int>> shape, Vector2D pos) : _shape(shape)
{
    this->setPos(pos);
}

Block::~Block() {}

void Block::print() const
{
    // std::cout << blockTypeNames[_type] << std::endl;

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

bool Block::isCollision(Vector2D<int> dir, Board &spc)
{
    // std::cout << spc.getRow() << spc.getCol() << std::endl;
    // 1. 이동 방향으로 블럭의 복사본을 공간 복사본으로 이동 시킨다.
    // obj.setPosX(obj.getPosX() + dir.getPosX());
    // obj.setPosY(obj.getPosY() + dir.getPosY());
    // this->setPos(this->getPos() + dir); // 먼저 이동을 해버려서 문제다
    Vector2D<int> pos = this->getPos() + dir;

    for (int i = 0; i < this->getHeight(); i++)
    {
        for (int j = 0; j < this->getWidth(); j++)
        {
            if (this->getShape()[i][j] == 1)
            {
                // 블럭이 벽에 충돌되었는지 바닥에 충돌되었는지 다른 블럭과 출돌되었는지 확인하면 됨
                // std::cout << spc.getRow() << spc.getCol() << std::endl;
                if ((pos.getPosY() + i) >= spc.getCol() || (pos.getPosY() + i) < 0)
                {
                    // std::cout << "case 1" << std::endl;
                    return true;
                }

                if ((pos.getPosX() + j) >= spc.getRow() || (pos.getPosX() + j) < 0)
                {
                    // std::cout << "case 2" << std::endl;
                    return true;
                }

                if (spc.getSpace()[pos.getPosY() + i][pos.getPosX() + j] == 1)
                {
                    // std::cout << "case 3" << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}

Board::Board() : _nRow(10), _nCol(20), _space(_nCol, std::vector<int>(_nRow, 0)) {}
Board::~Board() {}

// void Board::merge(Block &block) const {}

void Board::print() const
{
    clear();                        // ncurses 화면 청소
    mvprintw(0, 0, "############"); // 상단 테두리 출력

    int row = 1; // 출력 시작 행을 1로 설정
    for (const auto &cols : _space)
    {
        move(row, 0); // 커서 이동
        addch('#');   // 왼쪽 테두리 출력

        for (int elem : cols)
            addch((elem == 1) ? '@' : ' '); // 각 좌표의 셀 출력

        addch('#'); // 오른쪽 테두리 출력
        row++;      // 다음 행 이동
    }
    mvprintw(row, 0, "############"); // 하단 테두리 출력

    refresh(); // 모든 변경사항을 화면에 반영
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

void Board::_refresh(Block block)
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

bool Board::_flush(void)
{
    int cols = 0;
    while (cols < this->getCol())
    {
        int rows = 0;
        while (rows < this->getRow())
        {
            if (_space[cols][rows] == 1)
                rows++;
            else
                break;
        }
        if (rows == this->getRow())
            break;
        else
            cols++;
    }
    if (cols == this->getCol())
        return false;

    while (cols > 0)
    {
        for (int rows = 0; rows < this->getRow(); rows++)
            _space[cols][rows] = _space[cols - 1][rows];
        cols--;
    }

    for (int rows = 0; rows < this->getRow(); rows++)
        _space[cols][rows] = 0;

    return true;
}