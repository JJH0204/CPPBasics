#ifndef __TETRIS__
#define __TETRIS__

/* code */
namespace Tetris
{
    /* 게임 관리자 객체 */
    class GameManager
    {
    public:
        GameManager() {}
        ~GameManager() {}
        void Marge(Block block, Ground &ground);
    };

    /* 2차원 좌표계 계산 객체 */
    template <typename T>
    class Vector2
    {
    public:
        T _x, _y;
        Vector2() : _x(0), _y(0) {}
        Vector2(T x, T y) : _x(x), _y(y) {}
        ~Vector2() {}
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
    };

    /* 테트리스 게임 공간 객체 */
    class Ground
    {
    private:
        char **_ppGlobal;

    public:
        Ground();
        ~Ground() {}
    };

    Ground::Ground()
    {
        _ppGlobal = new char *[20];
        for (int i = 0; i < 20; i++)
        {
            *_ppGlobal = new char[10];
            for (int j = 0; j < 10; j++)
                _ppGlobal[i][j] = 0;
        }
    }

    Ground::~Ground()
    {
        for (int i = 0; i < 20; i++)
            delete[] _ppGlobal[i];
        delete[] _ppGlobal;
    }
}

#endif