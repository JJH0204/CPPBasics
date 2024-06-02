#ifndef __BOARD__
#define __BOARD__

class Board
{
public:
    int _nRow; /* 2차원 공간 가로 폭 */
    int _nCol; /* 2차원 공간 세로 폭 */
    bool **_ppBoolSpace;
    Board() : _nRow(10), _nCol(20)
    {
        /* 2차원 배열 공간 동적으로 생성(할당) */
        _ppBoolSpace = new bool *[_nCol];
        for (int i = 0; i < _nCol; i++)
            *(_ppBoolSpace + i) = new bool[_nRow];

        /* 동적 할당한 이차원 배열 전체를 0(false)로 초기화 */
        for (int i = 0; i < _nCol; i++)
            for (int j = 0; j < _nRow; j++)
                _ppBoolSpace[i][j] = false;
    }
    ~Board();

    void print(Block block);
};

Board::~Board()
{
    // 메모리 해제
    for (int i = 0; i < _nCol; i++)
    {
        delete[] _ppBoolSpace[i];
    }
    delete[] _ppBoolSpace;
}

void Board::print(Block block)
{
    std::cout << "############" << std::endl;
    for (int i = 0; i < _nCol; i++)
    {
        std::cout << "#";
        for (int j = 0; j < _nRow; j++)
        {
            if (i == block._y && j == block._x)
                std::cout << "@";
            else
                std::cout << " ";
        }
        std::cout << "#" << std::endl;
    }
    std::cout << "############" << std::endl;
}
#endif