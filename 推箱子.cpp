#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <stdint.h>
#include <stdint.h>

unsigned short int BOX = 0;											//箱子数目
unsigned short int mapcopy[8][8] = { 0 };					//地图的拷贝，用于重新开始比
unsigned short int point = 3;

unsigned short int map[8][8] = {							//空地0 箱子1 人2 目的地3 箱子+目的地4 人+目的地5  墙壁6
	6, 6, 6, 6, 6, 6, 6, 6,
	6, 0, 6, 0, 6, 0, 0, 6,
	6, 0, 0, 3, 6, 1, 0, 6,
	6, 0, 0, 6, 6, 0, 0, 6,
	6, 0, 0, 1, 0, 0, 0, 6,
	6, 0, 0, 1, 0, 0, 0, 6,
	6, 0, 6, 0, 0, 0, 2, 6,
	6, 6, 6, 6, 6, 6, 6, 6
};

unsigned short int map2[8][8] = {
	6, 6, 6, 6, 6, 6, 6, 6,
	6, 3, 0, 0, 6, 0, 0, 6,
	6, 6, 0, 0, 1, 0, 0, 6,
	6, 0, 0, 0, 6, 1, 0, 6,
	6, 0, 0, 6, 6, 0, 0, 6,
	6, 0, 1, 6, 6, 1, 2, 6,
	6, 0, 0, 6, 6, 0, 0, 6,
	6, 6, 6, 6, 6, 6, 6, 6
};

unsigned short int map3[8][8] = {
	6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 0, 0, 0, 0, 6, 6,
	6, 6, 1, 0, 0, 1, 0, 6,
	6, 6, 0, 6, 6, 6, 0, 6,
	6, 0, 0, 6, 6, 0, 0, 6,
	6, 0, 0, 6, 6, 0, 6, 6,
	6, 0, 1, 3, 6, 0, 2, 6,
	6, 6, 6, 6, 6, 6 ,6 ,6
};

void COPY(void)
{
	for (unsigned short int x = 0; x < 8; x++)
	{
		for (unsigned short int y = 0; y < 8; y++)
		{
			mapcopy[x][y] = map[x][y];
		}
	}
}

unsigned short int x, y;
unsigned short int X, Y;
unsigned short int x1 = 0;
unsigned short int y1 = 0;
unsigned short int box = 0;
char CE = '\0';

void draw(void)						//绘制地图
{
	for (unsigned short int x = 0; x < 8; x++)
	{
		for (unsigned short int y = 0; y < 8; y++)
		{
			switch (map[x][y])
			{
			case 0: printf("  "); break;
			case 6: printf("# "); break;
			case 3: printf("X "); break;
			case 1: printf("@ "); break;
			case 2: printf("o "); break;
			case 4: printf("$ "); map[x][y] = 3; break;
			case 5: printf("Q "); break;
			}
		}
		putchar('\n');
	}
}

void man(void)						//人坐标
{
	for (x = 0; x < 8; x++)
	{
		for (y = 0; y < 8; y++)
		{
			switch (map[x][y])
			{
			case 2: X = x; Y = y; break;
			}
		}
	}
}

void user(void)						//按键处理
{
	man();
	CE = getch();
	switch (CE)
	{
		case 'r':
		case 'R': 
			{
				for (unsigned short int x = 0; x < 8; x++)
				{
					for (unsigned short int y = 0; y < 8; y++)
					{
						point = 3;
						map[x][y] = mapcopy[x][y];
						man();
					}
				}
				break;
			}
		case 'w':
		case 'W': { switch (map[X - 1][Y])
			{
			case 0: if (map[X][Y] == 5)
				{
				map[X][Y] = 3; X -= 1; break;
				}
				  else map[X][Y] = 0; X -= 1; 
				break;
			case 3: map[X - 1][Y] = 5; X -= 1; map[X + 1][Y] = 0; break;
			case 1: if ((map[X - 2][Y]) == 0)
				{
					x1 = (X - 1); y1 = Y; map[x1][y1] = 0; x1 = (X - 2); y1 = Y; map[x1][y1] = 1; break;			//计算箱子的坐标
				}																									
				  if ((map[X - 2][Y]) == 3)																			//目的地判断
				  {
					  x1 = (X - 1); y1 = Y;
					  map[x1][y1] = 0;
					  map[x1 - 1][y1] = 4;
				  }
			}
				break;
		}
		case 'a':
		case 'A': { switch (map[X][Y - 1])
			{
			case 0:	if (map[X][Y] == 5)
		{
			map[X][Y] = 3; Y -= 1; break;
		}
				 else map[X][Y] = 0; Y -= 1;
			break;
			case 3: map[X][Y - 1] = 5; Y -= 1; map[X][Y + 1] = 0; break;
			case 1: if ((map[X][Y - 2]) == 0)
				{
					x1 = X; y1 = (Y - 1); map[x1][y1] = 0; x1 = X; y1 = (Y - 2); map[x1][y1] = 1; break;
				}
				  if ((map[X][Y - 2]) == 3)
				  {
					  x1 = X; y1 = (Y - 1);
					  map[x1][y1] = 0;
					  map[x1][y1 - 1] = 4;
				  }
			}
				break;
		}
		case 's':
		case 'S': { switch (map[X + 1][Y])
			{
			case 0:	if (map[X][Y] == 5)
		{
			map[X][Y] = 3; X += 1; break;
		}
				  else map[X][Y] = 0; X += 1; break;
			case 3: map[X + 1][Y] = 5; X += 1; map[X - 1][Y] = 0; break;
			case 1: if ((map[X + 2][Y]) == 0)
				{
					x1 = (X + 1); y1 = Y; map[x1][y1] = 0; x1 = (X + 2); y1 = Y; map[x1][y1] = 1; break;
				}
				  if ((map[X + 2][Y]) == 3)
				  {
					  x1 = (X + 1); y1 = Y;
					  map[x1][y1] = 0;
					  map[x1 + 1][y1] = 4;
				  }
			}
				break;
		}
		case 'd':
		case 'D': { switch (map[X][Y + 1])
			{
		case 0: if (map[X][Y] == 5)
		{
			map[X][Y] = 3; Y += 1; break;
		}
			  else map[X][Y] = 0; Y += 1; break;
			case 3: map[X][Y + 1] = 5; Y += 1; map[X][Y - 1] = 0; break;
			case 1: if ((map[X][Y + 2]) == 0)
				{
					x1 = X; y1 = (Y + 1); map[x1][y1] = 0; x1 = X; y1 = (Y + 2); map[x1][y1] = 1; break;
				}
				  if ((map[X][Y + 2]) == 3)
				  {
					  x1 = X; y1 = (Y + 1);
					  map[x1][y1] = 0;
					  map[x1][y1 + 1] = 4;
				  }
			}
				break;
		}
		case 'Q':
		case 'q': point = 0; BOX = 0; break;
	}

	if (map[X][Y] == 5)
	{
		map[X][Y] = 5;
	}
	else map[X][Y] = 2;
}

void BOXS(void)
{
	box = 0;
	for (unsigned short int x = 0; x < 8; x++)							//试图寻找箱子的坐标
	{
		for (unsigned short int y = 0; y < 8; y++)
		{
			switch (map[x][y])
			{
			case 1: box += 1; break;
			}

		}
	}
	BOX = box;
	if (BOX == 0)
	{
		point--;
	}
}

int main(void)
{
	COPY();
	
	while (BOX || point)
	{
		BOXS();
		if (BOX == 0)
		{
			switch (point)
			{
			case 2: {
				for (unsigned short int x = 0; x < 8; x++)
				{
					for (unsigned short int y = 0; y < 8; y++)
					{
						map[x][y] = map2[x][y];
					}
				}
				break;
			}
			case 1: {
				for (unsigned short int x = 0; x < 8; x++)
				{
					for (unsigned short int y = 0; y < 8; y++)
					{
						map[x][y] = map3[x][y];
					}
				}
				break;
			}
				  break;
			default: break;
			}
		}

		if (point == 0)
		{
			system("cls");
			draw();
			break;
		}

		system("color f4");
		system("cls");
		draw();
		BOXS();
		printf("\n箱子数:%hu 关卡数:%hu\n\nR重新开始 Q退出 WASD移动\n", box, point);							// 打印提示
		user();
	}
	
	putchar('\n');

	system("echo 游戏结束,按任意键退出");
	x = getch();

	return 0;
}