#include "game.h"

extern unsigned short int count;

void Initboard(char board[ROW][LINE]) {
	for (unsigned short int i = 0; i < ROW; i++) {
		for (unsigned short int j = 0; j < LINE; j++) {
			board[i][j] = ' ';
		}
	}
}

void printboard(char board[ROW][LINE]) {
	printf("  ");
	for (unsigned short int e = 0; e < LINE; e++)
		printf("%2hu  ", (e + 1));
	putchar('\n');
	for (unsigned short int i = 0; i < ROW; i++) {
		for (unsigned short int j = 0; j < LINE; j++) {
			if (j == 0)
				printf("%-2hu", (i + 1));
			if (j != LINE - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c ", board[i][j]);
		}
		putchar('\n');
		if (i != ROW - 1) {
			printf("  ");
			for (unsigned short int i = 0; i < LINE; i++) {
				if (i != LINE - 1)
					printf("---|");
				else
					printf("---");
			}
			putchar('\n');
		}
	}		
	putchar('\n');
}

void player(char board[ROW][LINE], int row, int line) {
	do {
		printf("\n玩家 ->\n");
		printf("\n请输入棋子坐标，中间以空格分隔	");
		if (scanf("%d%d", &line, &row) != 2) {
			printf("输入错误，请重试\n");
			_sleep(1000);
			while (getchar() != '\n');
			continue;
		}
		else {
			if ((row > ROW) || (line > LINE)) {
				printf("数值过大，请重试\n");
				while (getchar() != '\n');
				_sleep(1000);
				continue;
			}
			else if ((row <= 0) || (line <= 0)) {
				printf("数值过小，请重试\n");
				while (getchar() != '\n');
				_sleep(1000);
				continue;
			}
			else if (board[row - 1][line - 1] == ' ') {
				board[row - 1][line - 1] = 'X';
				count++;
				break;
			}
			else {
				printf("这里已经有棋子了");
				_sleep(1000);
				continue;
			}
		}
	} while (1);
}

unsigned int randomX(void) {

	unsigned x = (rand() % LINE);
	return x;
}

unsigned int randomY(void) {
	unsigned y = (rand() % ROW);
	return y;
}

void bot(char board[ROW][LINE], unsigned int row, unsigned int line) {
	printf("电脑 ->\n");
	while (1) {
		if (board[row][line] == ' ') {
			board[row][line] = 'O';
			_sleep(1000);
			count++;
			break;
		}
		else {
			line = randomX();
			row = randomY();
		}
	}
}

unsigned short int winner(unsigned short int x, unsigned short int y, unsigned short int count, char piece ,char board[ROW][LINE]) {
	for (unsigned short int j = 0; j < y; j++) {														//水平方向判定
		unsigned short int cnt = 0;
		for (unsigned short int i = 0; i < x; i++) {
			if (board[j][i] == piece) {
				cnt++;
				if ((cnt == PIECE) && (piece == 'X')) {
					printf("\n玩家胜利\n");
					_sleep(1000);
					return 1;
				}
				else if ((cnt == PIECE) && (piece == 'O')) {
					printf("\n电脑胜利\n");
					_sleep(1000);
					return 1;
				}
			}
			else
				cnt = 0;
		}
	}

	for (unsigned short int j = 0; j < y; j++) {														//垂直方向判定
		unsigned short int cnt = 0;
		for (unsigned short int i = 0; i < x; i++) {
			if (board[i][j] == piece) {
				cnt++;
				if ((cnt == PIECE) && (piece == 'X')) {
					printf("\n玩家胜利\n");
					_sleep(1000);
					return 1;
				}
				else if ((cnt == PIECE) && (piece == 'O')) {
					printf("\n电脑胜利\n");
					_sleep(1000);
					return 1;
				}
			}
			else
				cnt = 0;
		}
	}

#if PIECE <= ROW																	//正斜方向判断

	for (unsigned short int line = 0; line <= (LINE - PIECE); line++) {
		unsigned short int cnt = 0;

		for (unsigned short int row = 0; row <= (ROW - PIECE); row++) {
			unsigned short int x = line;
			unsigned short int y = row;

			while ((x < LINE) && (y < ROW)) {
				if (board[x][y] == piece) {
					cnt++;
				}
				else {
					cnt = 0;
				}
				switch (piece) {
					case 'X': {
						if (cnt == PIECE) {
							printf("\n玩家胜利\n");
							_sleep(1000);
							return 1;
						}
						break;
					}

					case 'O': {
						if (cnt == PIECE) {
							printf("\n电脑胜利\n");
							_sleep(1000);
							return 1;
						}
						break;
					}
				}

				if ((x < LINE) && (y < ROW)) {
					x++, y++;
				}
			}
		}
	}

	for (unsigned short int line = (LINE - 1); line >= (PIECE - 1); line--) {				//反斜方向判断
		unsigned short int cnt = 0;

		for (unsigned short int row = 0; row < (ROW - PIECE + 1); row++) {
			short int x = line;
			unsigned short int y = row;

			while ((x >= 0) && (y < ROW)) {
				if (board[x][y] == piece) {
					cnt++;
				}
				else {
					cnt = 0;
				}
				switch (piece) {
					case 'X': {
						if (cnt == PIECE) {
							printf("\n玩家胜利\n");
							_sleep(1000);
							return 1;
						}
						break;
					}

					case 'O': {
						if (cnt == PIECE) {
							printf("\n电脑胜利\n");
							_sleep(1000);
							return 1;
						}
						break;
					}
				}

				if ((x >= 0) && (y < ROW)) {
					x--, y++;
				}
			}
		}
	}

#endif

		if (count == (x * y)) {
			printf("\n平局\n");
			_sleep(1000);
			return 1;
		}
		else {
			return 0;
		}
}