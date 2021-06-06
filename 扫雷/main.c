#include "game.h"

unsigned short int flag = 1;
unsigned short int _Bomb = BOMB;

void game(void) {
	do {
		menu();
		while (scanf("%hu", &flag) != 1) {
			printf("输入错误，请重试\n");
			while (getchar() != '\n');
		}

		switch (flag) {
			case 1: {
				initmap(LINE, ROW, BOMB);
				while (flag) {
					map(_Bomb);
					switch (findbomb()) {
						case -1: {
							system("cls");
							printf("\n很遗憾，你无了\n");
							Sleep(1000);
							flag = 0;
							break;
						}
						case 0: {
							system("cls");
							printf("\b你赢了\n");
							Sleep(1000);
							flag = 0;
							break;
						}
					}

				}
			}break;

			case 0: {
				printf("正在退出\n");
				_sleep(1000);
				exit(0);
			}break;

			default: {
				printf("输入错误，请重试\n");
			}
		}
	}while (1);
}

int main(void) {
	system("color F0");
	game();

	system("pause");
	return 0;
}