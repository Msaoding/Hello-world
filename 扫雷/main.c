#include "game.h"

unsigned short int flag = 1;
unsigned short int _Bomb = BOMB;

void game(void) {
	do {
		menu();
		while (scanf("%hu", &flag) != 1) {
			printf("�������������\n");
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
							printf("\n���ź���������\n");
							Sleep(1000);
							flag = 0;
							break;
						}
						case 0: {
							system("cls");
							printf("\b��Ӯ��\n");
							Sleep(1000);
							flag = 0;
							break;
						}
					}

				}
			}break;

			case 0: {
				printf("�����˳�\n");
				_sleep(1000);
				exit(0);
			}break;

			default: {
				printf("�������������\n");
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