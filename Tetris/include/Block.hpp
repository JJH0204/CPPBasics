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

class Block : public Vector2D<int>
{
private:
    BlockType _type;
    int _width, _height;
    std::vector<std::vector<int>> _shape;

    void copyShape(const int **sourceShape);

public:
    Block();
    Block(int x, int y);
    Block(Vector2D val);
    ~Block();

    int getWidth() { return _width; }
    int getHeight() { return _height; }

    void print() const;
};

#endif