#ifndef __BLOCK__
#define __BLOCK__

template <typename T>
class Vector2
{
private:
    T _x;
    T _y;

public:
    Vector2() : _x(0), _y(0) {}
    Vector2(T x, T y) : _x(x), _y(y) {}
    Vector2(const Vector2 &val) : _x(val._x), _y(val._y) {}
    ~Vector2() {}

    T getPosX() { return _x; }
    T getPosY() { return _y; }

    void setPosX(const T x) { _x = x; }
    void setPosY(const T y) { _y = y; }

    void setPos(const Vector2 &val)
    {
        this->_x = val._x;
        this->_y = val._y;
    }

    Vector2 operator+(const Vector2 &other) const { return Vector2(_x + other._x, _y + other._y); }

    Vector2 operator-(const Vector2 &other) const { return Vector2(_x - other._x, _y - other._y); }

    Vector2 operator*(T nScalar) const { return Vector2(_x - nScalar, _y - nScalar); }

    void gravity(T y) { _y += y; }
};

class Block : public Vector2<int>
{
private:
    
public:
    Block() {}
    Block(int x, int y)
    {
        this->setPosX(x);
        this->setPosY(y);
    }
    Block(Vector2 val)
    {
        this->setPosX(val.getPosX());
        this->setPosY(val.getPosY());
    }
    ~Block() {}
};

#endif