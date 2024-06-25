.PHONY: all project_Basics OOP Tetris

all: project_Basics OOP Tetris

project_Basics:
	$(MAKE) -C project_Basics

OOP:
	$(MAKE) -C OOP

Tetris:
	$(MAKE) -C Tetris
