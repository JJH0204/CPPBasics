#ifndef __BLOCK__
#define __BLOCK__

#include <vector>

template <typename T>
class Vector2D
{
private:
    T _x;
    T _y;

public:
    Vector2D() : _x(0), _y(0) {}
    Vector2D(T x, T y) : _x(x), _y(y) {}
    Vector2D(const Vector2D &val) : _x(val._x), _y(val._y) {}
    ~Vector2D() {}

    T getPosX() const { return _x; }
    T getPosY() const { return _y; }

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
};

enum BlockType
{
    I,
    O,
    T,
    S,
    Z,
    J,
    L
};

static const char *blockTypeNames[] = {"I", "O", "T", "S", "Z", "J", "L"};

class Block : public Vector2D<int>
{
private:
    int _width, _height;                  /* 블록 가로, 세로 폭 */
    BlockType _type;                      /* 블록 모양 식별 정보 */
    std::vector<std::vector<int>> _shape; /* 블록 모양 이차원 데이터 */

public:
    Block();
    Block(BlockType type, Vector2D vector2, int **shape);
    Block(Block &other);
    ~Block();

    int getWidth() { return _width; }
    int getHeight() { return _height; }
    BlockType getType() { return _type; }
    std::vector<std::vector<int>> getShape() { return _shape; }

    void setShape(int **sourceShape);

    void print() const;
};

#endif