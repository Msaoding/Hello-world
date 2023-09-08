#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "head.h"

int main(void) {
	unsigned short flag = 0;
	unsigned short arr[ROW + 2][LINE + 2] = {0}; //+2是因为地图边框会占两个位置

	srand((unsigned)time(NULL));

	do {
		menu();
		scanf("%hu", &flag);
		clean();

		switch (flag) {
			case 1:
				game(arr);
				break;
			case 2:
				return 0;
				break;
			default:
				printf("\r输入错误,请重试");
				Sleep(1500);
				system("cls");
		}
	} while (1);
}