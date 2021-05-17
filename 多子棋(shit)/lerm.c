#include <windows.h>
#include "game.h"
#include <conio.h>

_Bool flag = 1;
unsigned short int status = 0;
char board[ROW][LINE] = {'0'};										//��������
unsigned short int count = 0;										//���Ӽ�����

void draw(void) {
	system("cls");													//����
	printboard(board);												//��ӡ����
} 

void game(void) {													//��Ϸ�߼�
	draw();															//����ͼ��
	while (1) {														//����
		player(board, ROW, LINE);									//�������
		draw();														
		if (winner(LINE, ROW, count, 'X', board))					//������Ŀ���
			break;
		bot(board, randomY(), randomX());							//��������
		draw();
		if (winner(LINE, ROW, count, 'O', board))
			break;
	}
}

void menu(void) {													//��ӡ�˵�
	printf("\n*********************\n");
	printf("****1 ��ʼ 0 �˳�****\n");
	printf("*********************\n");
	printf("��ѡ��-> ");
}

void frame(void) {													//ѡ��˵�
	do
	{
		menu();
		scanf("%hu", &status);

		switch (status) {
		case 1 :
			printf("������\n");
			while (getchar() != '\n');
			Initboard(board);					 							//��ʼ������
			count = 0;
			game();
			break;
		case 0:
			printf("�����˳���Ϸ");
			Sleep(1000);
			exit(0);
			break;
		default:
			printf("�������������\n");
			while (getchar() != '\n');
		}
	} while (status);
}

int main(void) {													//������
	srand((unsigned int)time(NULL));
	frame();

	system("pause");
	return 0;
}