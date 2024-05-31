#ifndef __TETRIS__
#define __TETRIS__
#include <iostream>
#include <vector>
#include <cmath>
#include <conio.h>
#include <string>
#include "Terminal.h"

namespace Tetris
{
    /* 2차원 좌표계 계산 객체 */
    template <typename T>
    class Vector2
    {
    public:
        T _x, _y;
        Vector2() : _x(0), _y(0) {}
        Vector2(T x, T y) : _x(x), _y(y) {}
        ~Vector2() {}

        Vector2<T> operator+(const Vector2 &other) const
        {
            return Vector2(_x + other._x, _y + other._y);
        }

        Vector2<T> operator-(const Vector2 &other) const
        {
            return Vector2(_x - other._x, _y - other._y);
        }

        Vector2<T> operator*(const Vector2 &other) const
        {
            return Vector2(_x * other._x, _y * other._y);
        }

        T length(void) const
        {
            return std::sqrt(_x * _x + _y * _y);
        }

        Vector2 normalize(void) const
        {
            T len = length();
            return (len != 0) ? Vector2(_x / len, _y / len) : Vector2();
        }
        void print(void) const
        {
            std::cout << "(" << _x << "," << _y << ")" << std::endl;
        }
    };

    /* 테트리스 블럭 객체 */
    class Block
    {
    private:
        char _shape;
        Vector2<int> _pos;

    public:
        Block() : _shape('ㅁ'), _pos(Vector2(0, 0)) {}
        template <typename T>
        Block(char shape, Vector2<T> pos) : _shape(shape), _pos(pos) {}
        ~Block() {}

        Vector2<int> getPos() { return _pos; }
        void gravity(void);
    };

    void Block::gravity(void)
    {
        _pos = _pos + Vector2(0, 1);
        return;
    }

    /* 테트리스 게임 공간 객체 */
    class Ground
    {
    private:
        char **_ppGlobal;
        int _width;
        int _length;

    public:
        Ground();
        ~Ground();
        void Marge(Block block)
        {
            _ppGlobal[block.getPos()._y][block.getPos()._x] = !_ppGlobal[block.getPos()._y][block.getPos()._x];
        }

        void print(void)
        {
            for (int i = 0; i < _length; i++)
                Terminal().PrintNL(*(_ppGlobal + i), _width);
        }
    };

    Ground::Ground() : _width(10) , _length(20)
    {
        _ppGlobal = new char *[_length];
        for (int i = 0; i < _length; i++)
        {
            *_ppGlobal = new char[_width];
            for (int j = 0; j < _width; j++)
                _ppGlobal[i][j] = 0;
        }
    }

    Ground::~Ground()
    {
        for (int i = 0; i < 20; i++)
            delete[] _ppGlobal[i];
        delete[] _ppGlobal;
    }

    /* 게임 관리자 객체 */
    class GameManager
    {
        Block _Block;
        Ground _Ground;

    public:
        GameManager() {}
        ~GameManager() {}
        void update(void);
    };

    void Tetris::GameManager::update(void)
    {
        while (1)
        {
            Terminal().Clear();
            _Ground.Marge(_Block);
            _Ground.print();
            _Ground.Marge(_Block);
            _Block.gravity();
        }
    }
}
#endif