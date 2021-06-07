#ifndef _GAME_
#define _GAME_

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define LINE 10
#define ROW 10
#define BOMB 15

char board[ROW][LINE];

void game(void);
void menu(void);
void map(unsigned short int bomb);
void initmap(unsigned short int line, unsigned short int row, unsigned short int bomb);
short int findbomb(void);
void scanbomb(char board[ROW][LINE], short int line, short int row);


#endif