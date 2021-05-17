#define LINE 15							//���̳�
#define ROW 15							//���̿�
#define PIECE 5							//���ٿ������ж�ʤ��

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Initboard(char board[ROW][LINE]);																		//��ʼ������
void printboard(char board[ROW][LINE]);																		//��������
void player(char board[ROW][LINE], int row, int line);														//����ƶ�
void bot(char board[ROW][LINE], unsigned int row, unsigned int line);										//�����ƶ�
unsigned short int winner(unsigned short int, unsigned short int, unsigned short int count, char piece, char board[ROW][LINE]);	//ʤ���ж�
unsigned int randomX(void);																					//���X����
unsigned int randomY(void);																					//���Y����