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

    T getPosX() const { return _x; }
    T getPosY() const { return _y; }

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

class Block : public Vector2<int>
{
private:
    BlockType _type;
    int _width, _height;
    int **_ppShape;

    void allocShape(void);
    void copyShape(const int **sourceShape);

public:
    Block();
    Block(int x, int y);
    Block(Vector2 val);
    // Block(const BlockType type, const int ppShape[4][4]);
    // Block(const Block &other);
    ~Block();

    int getWidth() { return _width; }
    int getHeight() { return _height; }
    int **getShape() { return _ppShape; }

    void print() const;
};

#endif