#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "head.h"

//�غϼ�����
unsigned short count = 0;
//��¼����λ��
unsigned short row = 0;
unsigned short line = 0;

//���ڴ�ӡ�˵�
void menu(void) {
	printf("##############################################\n");
	printf("##############################################\n");
	printf("#########    1.��ʼ��Ϸ   2.�˳�    ##########\n");
	printf("##############################################\n");
	printf("##############################################\n");
	printf("��ѡ��>:");
}

//����������뻺����
void clean(void) {
	while (getchar() != '\n');
}

//���ڳ�ʼ������
void initialize(unsigned short arr[ROW + 2][LINE + 2]) {
	for (unsigned y = 0; y < (ROW + 2); y++) {
		for (unsigned x = 0; x < (LINE + 2); x++) {
			if (y == 0 || x == 0 || x == (LINE + 1) || y == (ROW + 1)) {
				arr[y][x] = 3;
			}
			else {
				arr[y][x] = 0;
			}
		}
	}
}

//���ڴ�ӡ��ͼ
void printmap(unsigned short arr[ROW + 2][LINE + 2]) {
	for (unsigned short y = 0; y < (ROW + 2); y++) {
		for (unsigned short x = 0; x < (LINE + 2); x++) {
			if (arr[y][x] == WALL) {
				printf(" #");
			}
			else if (arr[y][x] == SPACE) {
				printf("  ");
			}
			else if (arr[y][x] == PLAYER) {
				printf(" X");
			}
			else if (arr[y][x] == COMPUTER) {
				printf(" O");
			}
		}

		putchar('\n');
	}
}

//�����жϻغ�
unsigned short round(void) {

	if (count == 0) {
		return (count = (rand() % 2 + 1));
	}
	else if (count == 1) {
		return ++count;
	}
	else {
		return --count;
	}
}

//�����ж�
unsigned short judge(unsigned short arr[ROW + 2][LINE + 2], unsigned short row, unsigned short line) {
	if (arr[row][line] == SPACE) {
		return 1;
	}
	else {
		return 0;
	}
}

//������Һ͵��Ե����벢����
void input(unsigned short arr[ROW + 2][LINE + 2], unsigned short sign) {

	switch (sign) {
		case PLAYER:
			printf("��һغ�>:");

			while (1) {
				while (scanf("%hu %hu", &row, &line) != 2 || row > ROW || line > LINE) {
					printf("\r�������");
					Sleep(1000);
					clean();
					system("cls");
					printmap(arr);
					printf("��һغ�>:");
				}

				if (judge(arr, row, line) == 0) {
					printf("�˴��ѱ�ռ�ã�����������");
					Sleep(2000);
					clean();
					system("cls");
					printmap(arr);
					printf("��һغ�>:");
				}
				else {
					break;
				}
			}
			

			arr[row][line] = PLAYER;

			break;
		case COMPUTER:
			printf("���Իغ�");

			while (1) {
				row = (rand() % ROW + 1);
				line = (rand() % LINE + 1);

				if (judge(arr, row, line)) {
					break;
				}
			}

			arr[row][line] = COMPUTER;
			Sleep(1000);

			break;
	}
}

//����Ƿ�������������
unsigned short scan(unsigned short arr[ROW + 2][LINE + 2], unsigned short row, unsigned short line) {
	unsigned short temp = 0;
	unsigned short sign = arr[row][line];

	for (unsigned short y = row; arr[y][line] != WALL; y++) {
		if (arr[y][line] == sign) {
			temp++;
		}
	}
	for (unsigned short y = row; arr[y][line] != WALL; y--) {
		if (arr[y][line] == sign) {
			temp++;
		}
	}

	if (temp > WIN) {
		return sign;
	}
	else {
		temp = 0;
	}

	for (unsigned short x = line; arr[row][x] != WALL; x++) {
		if (arr[row][x] == sign) {
			temp++;
		}
	}
	for (unsigned short x = line; arr[row][x] != WALL; x--) {
		if (arr[row][x] == sign) {
			temp++;
		}
	}

	if (temp > WIN) {
		return sign;
	}
	else {
		temp = 0;
	}

	for (unsigned short x = line, y = row; arr[y][x] != WALL; x--, y--) {
		if (arr[y][x] == sign) {
			temp++;
		}
		else {
			break;
		}
	}
	for (unsigned short x = line, y = row; arr[y][x] != WALL; x++, y++) {
		if (arr[y][x] == sign) {
			temp++;
		}
		else {
			break;
		}
	}

	if (temp > WIN) {
		return sign;
	}
	else {
		temp = 0;
	}

	for (unsigned short x = line, y = row; arr[y][x] != WALL; x++, y--) {
		if (arr[y][x] == sign) {
			temp++;
		}
		else {
			break;
		}
	}
	for (unsigned short x = line, y = row; arr[y][x] != WALL; x--, y++) {
		if (arr[y][x] == sign) {
			temp++;
		}
		else {
			break;
		}
	}

	if (temp > WIN) {
		return sign;
	}
	else {
		temp = 0;
	}

	return 0;
}

void game(unsigned short arr[ROW + 2][LINE + 2]) {
	unsigned short temp = 0;
	//��¼��λ
	unsigned space = (ROW * LINE);

	initialize(arr);
	
	while (1) {
		system("cls");
		printmap(arr);
		input(arr, round());

		temp = scan(arr, row, line);
		space--;

		if (temp == PLAYER) {
			system("cls");
			printmap(arr);
			printf("\r���ʤ��");
			Sleep(3000);
			break;
		}
		else if (temp == COMPUTER) {
			system("cls");
			printmap(arr);
			printf("\r����ʤ��");
			Sleep(3000);
			break;
		}
		else if (space == 0) {
			system("cls");
			printmap(arr);
			printf("\rƽ��  ");
			Sleep(3000);
			break;
		}
	}

	system("cls");
}