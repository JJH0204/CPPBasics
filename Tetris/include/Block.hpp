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
    bool **_ppShape;

    void allocShape(void)
    {
        _ppShape = new bool *[this->getHeight()];
        for (int i = 0; i < this->getHeight(); i++)
            *(_ppShape + i) = new bool[this->getWidth()];
    }

    // _ppShape 배열을 다른 Block 객체로부터 복사하는 함수
    void copyShape(const bool **sourceShape)
    {
        for (int i = 0; i < this->getHeight(); i++)
            for (int j = 0; j < this->getWidth(); j++)
                _ppShape[i][j] = sourceShape[i][j];
    }

public:
    Block() : _width(4), _height(4)
    {
        this->setPosX(0);
        this->setPosY(0);
        this->allocShape();
    }
    Block(int x, int y) : _width(4), _height(4)
    {
        this->setPosX(x);
        this->setPosY(y);
        this->allocShape();
    }
    Block(Vector2 val) : _width(4), _height(4)
    {
        this->setPosX(val.getPosX());
        this->setPosY(val.getPosY());
        this->allocShape();
    }
    Block(const BlockType type, const int width, const int height, const bool ppShape[4][4]) : _type(type), _width(width), _height(height)
    {
        this->setPosX(0);
        this->setPosY(0);
        this->allocShape();
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                _ppShape[i][j] = ppShape[i][j];
    }
    // 복사 생성자
    Block(const Block &other) : Vector2<int>(other), _type(other._type), _width(other._width), _height(other._height)
    {
        this->allocShape();
        this->copyShape(const_cast<const bool **>(other._ppShape)); // 상수성 유지
    }

    ~Block()
    {
        for (int i = 0; i < this->getHeight(); i++)
            delete[] _ppShape[i];
        delete[] _ppShape;
    }

    int getWidth() { return _width; }
    int getHeight() { return _height; }
    bool **getShape() { return _ppShape; }

    // void addShape(const bool **shape);
};

// void Block::addShape(const bool **shape)
// {
//     for (int i = 0; i < this->getHeight(); i++)
//         for (int j = 0; j < this->getWidth(); j++)
//             _ppShape[i][j] = shape[i][j];
// }

// class BlockManager
// {
// private:
//     Block *_pBlockList;

// public:
//     BlockManager();
//     ~BlockManager();
// };

// BlockManager::BlockManager()
// {
//     _pBlockList = new Block[28];

//     // _pBlockList[0].addShape({{1,1,0,0},{0,1,1,0},{0,0,0,0},{}})
//     /* 블록 모양 정보를 효율적으로 관리할 수 있는 방법을 연구해 보자 */
// }

// BlockManager::~BlockManager()
// {
//     delete[] _pBlockList;
// }

#endif