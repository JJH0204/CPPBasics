CC=gcc
CFLAGS=-I/mingw32/include/ncurses
LDFLAGS=-L/mingw32/lib -lncursesw

Tetris: main.o GameManager.o Block.o Board.o
    $(CC) -o Tetris main.o GameManager.o Block.o Board.o $(LDFLAGS)

main.o: main.cpp
    $(CC) -c main.cpp $(CFLAGS)

GameManager.o: GameManager.cpp
    $(CC) -c GameManager.cpp $(CFLAGS)

Block.o: Block.c
    $(CC) -c Block.cpp $(CFLAGS)

Board.o: Board.c
    $(CC) -c Board.cpp $(CFLAGS)
