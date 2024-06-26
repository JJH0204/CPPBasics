#pragma once
#include <vector>

namespace obj
{
    class Board; /* Board 객체의 포워드 선언 */

    template <typename T>
    class Vector2D
    {
    private:
        T _x;
        T _y;

    public:
        Vector2D() : _x(4), _y(0) {}
        Vector2D(T x, T y) : _x(x), _y(y) {}
        Vector2D(const Vector2D &val) : _x(val._x), _y(val._y) {}
        ~Vector2D() {}

        T getPosX() const { return _x; }
        T getPosY() const { return _y; }
        Vector2D getPos() const { return Vector2D(this->getPosX(), this->getPosY()); }

        void setPosX(const T x) { _x = x; }
        void setPosY(const T y) { _y = y; }

        void setPos(const Vector2D &val)
        {
            this->_x = val._x;
            this->_y = val._y;
        }

        Vector2D operator+(const Vector2D &other) const { return Vector2D(_x + other._x, _y + other._y); }

        Vector2D operator-(const Vector2D &other) const { return Vector2D(_x - other._x, _y - other._y); }

        Vector2D operator*(T nScalar) const { return Vector2D(_x - nScalar, _y - nScalar); }

        void gravity(T y) { _y += y; }
        void move(Vector2D<int> dir) { this->setPos(this->getPos() + dir); }
    };

    static const char blockTypeNames[] = {'I', 'O', 'T', 'S', 'Z', 'J', 'L'};

    class Block : public Vector2D<int>
    {
    private:
        int _width, _height;                  /* 블록 가로, 세로 폭 */
        std::vector<std::vector<int>> _shape; /* 블록 모양 이차원 데이터 */

    public:
        Block();
        Block(std::vector<std::vector<int>> shape, Vector2D pos);
        ~Block();

        int getWidth() { return _width; }
        int getHeight() { return _height; }
        std::vector<std::vector<int>> getShape() { return _shape; }

        void setShape(const std::vector<std::vector<int>> &sourceShape) { _shape = sourceShape; }
        void print() const;
        std::vector<std::vector<int>> rotate();

        bool isCollision(Vector2D<int> dir, Board &spc);
    };

    class Board
    {
    private:
        int _nRow, _nCol;                     /* 2차원 공간 가로, 세로 폭 */
        std::vector<std::vector<int>> _space; /* 2차원 게임 공간 */

    public:
        Board();
        ~Board();

        int getRow() { return _nRow; }
        int getCol() { return _nCol; }
        std::vector<std::vector<int>> getSpace() { return _space; }

        void setRow(int Row) { _nRow = Row; }
        void setCol(int Col) { _nCol = Col; }

        void print() const;
        void display(Block block);
        void _refresh(Block block);
        // bool isCollision(Vector2D<int> dir, Block block);

        bool _flush(void);   // 가로 한줄 완성 시 사라지게 하고 true 반환
    };
}
