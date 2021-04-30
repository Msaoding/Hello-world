//球球带作战
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <graphics.h>															//第三方图形库graphics
#include <conio.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
#define HIGH 640																//地图高
#define WIDTH 1024																//地图长
#define FOOD_NUM 800															//食物数量
#define MAP_HIGH (HIGH * 3)
#define MAP_WIDTH (WIDTH * 3)
//地图
IMAGE map(MAP_WIDTH, MAP_HIGH);
//摄像机
POINT camrea;

struct ball {
	int x = 0, y = 0, r = 0;													//地图的长宽和小球的半径
	unsigned short int color = 0;												//颜色
	bool flag = true;															//判断是否存活
};
struct ball player;																//玩家
struct ball food[FOOD_NUM];														//食物
void game(void) {																//初始化玩家参数
	srand((unsigned int)time(NULL));											//将时间戳作为随机数种子
	player.x = rand() % WIDTH;					
	player.y = rand() % HIGH;
	player.r = 10;
	player.color = RGB(rand() % 256, rand() % 256, rand() % 256);				//随机玩家颜色
	player.flag = true;															//存活状态
//初始化食物
	for (unsigned short int i = 0; i < FOOD_NUM; i++) {							//随机化食物参数
		food[i].x = (rand() % MAP_WIDTH);
		food[i].y = (rand() % MAP_HIGH);
		food[i].r = (rand() % 5 + 1);
		food[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);			//随机食物颜色
		food[i].flag = true;													//初始存活状态
	}
	mciSendString(L"open caidousenlin.mp3 alias BGM", NULL, NULL, NULL);		//播放背景音乐
	mciSendString(L"play BGM", NULL, NULL, NULL);				
}

void move(unsigned int speed) {													//异步按键获取
	if (GetAsyncKeyState(VK_UP)) {
		player.y -= speed;
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		player.y += speed;
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		player.x -= speed;
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		player.x += speed;
	}
	if (player.x > MAP_WIDTH)
		player.x = 0;
	if (player.x < 0)
		player.x = MAP_WIDTH;
	if (player.y > MAP_HIGH)
		player.y = 0;
	if (player.y < 0)
		player.y = MAP_HIGH;
}

void drawline(void) {															//绘制地图上的小格子
	setlinecolor(RGB(232, 232, 236));
	for (unsigned short int y = 10; y < MAP_WIDTH; y += 10) {
		line(0, y, MAP_WIDTH, y);												//横线
		line(y, 0, y, MAP_HIGH);												//竖线
	}
}

double distance(struct ball* b1, struct ball* b2) {								//判断玩家和食物之间的距离
	return sqrt((b1->x - b2->x) * (b1->x - b2->x) + (b1->y - b2->y) * (b1->y - b2->y));
}

void drawfood(void) {
	for (unsigned short int i = 0; i < FOOD_NUM; i++) {							//绘制食物
		if (food[i].flag && distance(&food[i], &player) > player.r) {
			setfillcolor(food[i].color);										//随机颜色
			solidcircle(food[i].x, food[i].y, food[i].r);						//随机生成食物
		}
		else {
			food[i].flag = true;
			food[i].x = rand() % MAP_WIDTH;
			food[i].y = rand() % MAP_HIGH;
			food[i].r = rand() % 5 + 1;
		}
	}
}

void gamemap(void) {															//绘制地图
	BeginBatchDraw();															//绘制开始
	SetWorkingImage(&map);														//设置图片map
	cleardevice();																//清除图形
	setbkcolor(WHITE);
	drawline();																	//绘制格子
	drawfood();																	//绘制食物

	setfillcolor(player.color);													//设置小球颜色
	solidcircle(player.x, player.y, player.r);									//设置小球的初始位置
	SetWorkingImage();															//回到默认图片
	putimage(0, 0, WIDTH, HIGH, &map, camrea.x, camrea.y);						//输出map
	{
		camrea.x = player.x - WIDTH / 2;										//设置摄像机位置
		camrea.y = player.y - HIGH  / 2;
		if (camrea.x < 0)
			camrea.x = 0;
		if (camrea.y < 0)
			camrea.y = 0;
		if (camrea.x > MAP_WIDTH - WIDTH)
			camrea.x = MAP_WIDTH - WIDTH;
		if (camrea.y > MAP_HIGH - HIGH)
			camrea.y = MAP_HIGH - HIGH;
	}

	Sleep(10);
	move(4);																	//玩家移动
	FlushBatchDraw();															//结束绘制
}

void PlayerEat(void) {															//玩家吃食物
	for (unsigned short int i = 0; i < FOOD_NUM; i++) {
		if (food[i].flag && distance(&food[i], &player) < player.r) {
			food[i].flag = false;
			player.r += food[i].r / 2;
		}
	}
}
//主函数
int main(void) {
#if _WIN32
	game();
	initgraph(WIDTH, HIGH, 1);													//创建地图
	printf("%d%d%d%d\n\ngamestart!", player.x, player.y, player.r, player.flag);//用于测试变量是否被正确初始化
	drawfood();
	while (1) {
		gamemap();
		PlayerEat();
	}
	closegraph();																//关闭图形窗口

	return 0;
#else
	printf("应用程序不兼容此操作系统\n");
	getchar();
	exit(-1);
#endif
}