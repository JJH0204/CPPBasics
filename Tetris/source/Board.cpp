#include "Board.hpp"

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
