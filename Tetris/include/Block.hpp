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
    bool **_ppShape;

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

    void addShape(const bool **shape);
};

void Block::addShape(const bool **shape)
{
    _ppShape = new bool *[4];
    for (int i = 0; i < 4; i++)
        *(_ppShape + i) = new bool[4];

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            _ppShape[i][j] = shape[i][j];
}

class BlockManager
{
private:
    Block *_pBlockList;

public:
    BlockManager();
    ~BlockManager();
};

BlockManager::BlockManager()
{
    _pBlockList = new Block[28];

    _pBlockList[0].addShape({{1,1,0,0},{0,1,1,0},{0,0,0,0},{}})
}

BlockManager::~BlockManager()
{
    delete[] _pBlockList;
}

#endif