#define LINE 15							//棋盘长
#define ROW 15							//棋盘宽
#define PIECE 5							//多少颗棋子判定胜利

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char board[ROW][LINE]);																		//初始化棋盘
void printboard(char board[ROW][LINE]);																		//绘制棋盘
void player(char board[ROW][LINE], int row, int line);														//玩家移动
void bot(char board[ROW][LINE], unsigned int row, unsigned int line);										//电脑移动
unsigned short int winner(unsigned short int, unsigned short int, unsigned short int count, char piece, char board[ROW][LINE]);	//胜负判定
unsigned int randomX(void);																					//随机X坐标
unsigned int randomY(void);																					//随机Y坐标