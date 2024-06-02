#ifndef __BLOCK__
#define __BLOCK__

class Block
{
public:
    int _x; /* 블럭의 x 좌표 */
    int _y; /* 블럭의 y 좌표 */
    Block() : _x(0), _y(0) {}
    Block(int x, int y) : _x(x), _y(y) {}
    ~Block() {}
};

#endif