#include <windows.h>
#include "game.h"
#include <conio.h>

_Bool flag = 1;
unsigned short int status = 0;
char board[ROW][LINE] = {'0'};										//创建棋盘
unsigned short int count = 0;										//棋子计数器

void draw(void) {
	system("cls");													//清屏
	printboard(board);												//打印棋盘
} 

void game(void) {													//游戏逻辑
	draw();															//绘制图像
	while (1) {														//下棋
		player(board, ROW, LINE);									//玩家下棋
		draw();														
		if (winner(LINE, ROW, count, 'X', board))					//棋子数目检测
			break;
		bot(board, randomY(), randomX());							//电脑下棋
		draw();
		if (winner(LINE, ROW, count, 'O', board))
			break;
	}
}

void menu(void) {													//打印菜单
	printf("\n*********************\n");
	printf("****1 开始 0 退出****\n");
	printf("*********************\n");
	printf("请选择-> ");
}

void frame(void) {													//选择菜单
	do
	{
		menu();
		scanf("%hu", &status);

		switch (status) {
		case 1 :
			printf("三子棋\n");
			while (getchar() != '\n');
			Initboard(board);					 							//初始化棋盘
			count = 0;
			game();
			break;
		case 0:
			printf("即将退出游戏");
			Sleep(1000);
			exit(0);
			break;
		default:
			printf("输入错误，请重试\n");
			while (getchar() != '\n');
		}
	} while (status);
}

int main(void) {													//主函数
	srand((unsigned int)time(NULL));
	frame();

	system("pause");
	return 0;
}