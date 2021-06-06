#include "game.h"

extern _Bomb;

void menu(void) {
	system("cls");
	printf("====================\n");
	printf("====== 1 play ======\n");
	printf("====== 0 exit ======\n");
	printf("====================\n");
}

void initmap(unsigned short int line, unsigned short int row, unsigned short int bomb) {		//初始化棋盘
	for (unsigned short int row = 0; row < ROW; row++) {							//3为隐藏的地块 0为空地 1为地雷
		for (unsigned short int line = 0; line < LINE; line++) {
			board[row][line] = 3;
		}
	}

	srand((unsigned int)time(NULL));
	do {
		unsigned short int random_x = rand() % line;
		unsigned short int random_y = rand() % row;

		if (board[random_y][random_x] == 3) {
			board[random_y][random_x] = 1;
			bomb--;
		}
		else {
			continue;
		}

	} while (bomb);
}

void map(unsigned short int bomb) {
	system("cls");
	printf("   ");
	for (unsigned short int line = 0; line < LINE; line++) {			//打印列
		printf("%-2hu", line + 1);
	}
	putchar('\n');

	for (unsigned short int row = 0; row < ROW; row++) {
		printf("%2hu ", row + 1);
		for (unsigned short int line = 0; line < LINE; line++) {
			if (board[row][line] == 3 || board[row][line] == 1) {
				printf("%c ", 22);
			}
			else if (board[row][line] == 0) {
				printf("  ");
			}
			else {
				printf("%c ", board[row][line]);
			}
		}
		putchar('\n');
	}
	printf("\n地雷数: %hu", bomb);
}

short int findbomb(void) {
	short int row;
	short int line;

	printf("\n请输入坐标\n");
	do {
		while (scanf("%hd%hd", &line, &row) != 2) {
			printf("输入错误，请重试	");
			while (getchar() != '\n');
		}
		if (line > LINE || row > ROW || row < 0 || line < 0) {
			printf("\n数值错误,请重试\n");
		}
	} while (line > LINE || row > ROW || row < 0 || line < 0);

	if (board[row - 1][line - 1] == 1) {				//踩雷
		return -1;
	}
	else {
		board[row - 1][line - 1] = 0;
	}

	scanbomb(board, line - 1, row - 1);

	unsigned short int count = 0;
	for (unsigned short int row = 0; row < ROW; row++) {
		for (unsigned short int line = 0; line < LINE; line++) {
			if (board[row][line] == 3) {
				count++;
			}
		}
	}
	if (count == 0) {
		return 0;
	}

	return 1;
}

void scanbomb(char board[ROW][LINE], short int line, short int row) {
	_Bool flag = 1;
	unsigned short int count = 0;

	for (short int y = row - 1; y <= row + 1; y++) {
		for (short int x = line - 1; x <= line + 1; x++) {
			if (x >= 0 && x < LINE && y >= 0 && y < ROW) {
				switch (board[y][x]) {
				case 3: if (flag) board[y][x] = 0; break;
				case 1: count++; flag = 0; break;
				}
			}
		}
	}

	if (count > 0) {
		board[row][line] = (char)(count + 48);
	}
}