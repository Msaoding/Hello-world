#ifndef __GAME__
#define __GAME__

//��ͼ��С
#define LINE 3
#define ROW 3

//����ȷ������
#define SPACE 0
#define PLAYER 1
#define COMPUTER 2
#define WALL 3

//ʤ������
#define WIN 3

void menu(void);
void clean(void);
void game(unsigned short arr[ROW + 2][LINE + 2]);
void initialize(unsigned short arr[ROW + 2][LINE + 2]);
void printmap(unsigned short arr[ROW + 2][LINE + 2]);
void input(unsigned short arr[ROW + 2][LINE + 2], unsigned short sign);
unsigned short round(void);
unsigned short judge(unsigned short arr[ROW + 2][LINE + 2], unsigned short row, unsigned short line);
unsigned short scan(unsigned short arr[ROW + 2][LINE + 2], unsigned short row, unsigned short line);

#endif