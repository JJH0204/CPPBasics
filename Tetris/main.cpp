/* 테트리스 구현 프로젝트 */
#include <iostream>
#include <cstdlib>
#include "GameManager.h"

void clearTerminal(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main(int argc, char *argv[])
{
    GameManager GameManager;
    clearTerminal();
    GameManager.WorkOut();
    
    
    
    return 0;
}