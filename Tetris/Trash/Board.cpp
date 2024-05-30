#include "Board.h"

void Board::Print(void)
{
    for (int i = 0; i < 22; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (this->_Field[i][j] == WALL)
                Terminal().Print("#");
            else if (this->_Field[i][j] == FULL)
                Terminal().Print("@");
            else
                Terminal().Print(" ");
        }
        Terminal().PrintNL("");
    }
}