//�������ս
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <graphics.h>															//������ͼ�ο�graphics
#include <conio.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")
#define HIGH 640																//��ͼ��
#define WIDTH 1024																//��ͼ��
#define FOOD_NUM 800															//ʳ������
#define MAP_HIGH (HIGH * 3)
#define MAP_WIDTH (WIDTH * 3)
//��ͼ
IMAGE map(MAP_WIDTH, MAP_HIGH);
//�����
POINT camrea;

struct ball {
	int x = 0, y = 0, r = 0;													//��ͼ�ĳ����С��İ뾶
	unsigned short int color = 0;												//��ɫ
	bool flag = true;															//�ж��Ƿ���
};
struct ball player;																//���
struct ball food[FOOD_NUM];														//ʳ��
void game(void) {																//��ʼ����Ҳ���
	srand((unsigned int)time(NULL));											//��ʱ�����Ϊ���������
	player.x = rand() % WIDTH;					
	player.y = rand() % HIGH;
	player.r = 10;
	player.color = RGB(rand() % 256, rand() % 256, rand() % 256);				//��������ɫ
	player.flag = true;															//���״̬
//��ʼ��ʳ��
	for (unsigned short int i = 0; i < FOOD_NUM; i++) {							//�����ʳ�����
		food[i].x = (rand() % MAP_WIDTH);
		food[i].y = (rand() % MAP_HIGH);
		food[i].r = (rand() % 5 + 1);
		food[i].color = RGB(rand() % 256, rand() % 256, rand() % 256);			//���ʳ����ɫ
		food[i].flag = true;													//��ʼ���״̬
	}
	mciSendString(L"open caidousenlin.mp3 alias BGM", NULL, NULL, NULL);		//���ű�������
	mciSendString(L"play BGM", NULL, NULL, NULL);				
}

void move(unsigned int speed) {													//�첽������ȡ
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

void drawline(void) {															//���Ƶ�ͼ�ϵ�С����
	setlinecolor(RGB(232, 232, 236));
	for (unsigned short int y = 10; y < MAP_WIDTH; y += 10) {
		line(0, y, MAP_WIDTH, y);												//����
		line(y, 0, y, MAP_HIGH);												//����
	}
}

double distance(struct ball* b1, struct ball* b2) {								//�ж���Һ�ʳ��֮��ľ���
	return sqrt((b1->x - b2->x) * (b1->x - b2->x) + (b1->y - b2->y) * (b1->y - b2->y));
}

void drawfood(void) {
	for (unsigned short int i = 0; i < FOOD_NUM; i++) {							//����ʳ��
		if (food[i].flag && distance(&food[i], &player) > player.r) {
			setfillcolor(food[i].color);										//�����ɫ
			solidcircle(food[i].x, food[i].y, food[i].r);						//�������ʳ��
		}
		else {
			food[i].flag = true;
			food[i].x = rand() % MAP_WIDTH;
			food[i].y = rand() % MAP_HIGH;
			food[i].r = rand() % 5 + 1;
		}
	}
}

void gamemap(void) {															//���Ƶ�ͼ
	BeginBatchDraw();															//���ƿ�ʼ
	SetWorkingImage(&map);														//����ͼƬmap
	cleardevice();																//���ͼ��
	setbkcolor(WHITE);
	drawline();																	//���Ƹ���
	drawfood();																	//����ʳ��

	setfillcolor(player.color);													//����С����ɫ
	solidcircle(player.x, player.y, player.r);									//����С��ĳ�ʼλ��
	SetWorkingImage();															//�ص�Ĭ��ͼƬ
	putimage(0, 0, WIDTH, HIGH, &map, camrea.x, camrea.y);						//���map
	{
		camrea.x = player.x - WIDTH / 2;										//���������λ��
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
	move(4);																	//����ƶ�
	FlushBatchDraw();															//��������
}

void PlayerEat(void) {															//��ҳ�ʳ��
	for (unsigned short int i = 0; i < FOOD_NUM; i++) {
		if (food[i].flag && distance(&food[i], &player) < player.r) {
			food[i].flag = false;
			player.r += food[i].r / 2;
		}
	}
}
//������
int main(void) {
#if _WIN32
	game();
	initgraph(WIDTH, HIGH, 1);													//������ͼ
	printf("%d%d%d%d\n\ngamestart!", player.x, player.y, player.r, player.flag);//���ڲ��Ա����Ƿ���ȷ��ʼ��
	drawfood();
	while (1) {
		gamemap();
		PlayerEat();
	}
	closegraph();																//�ر�ͼ�δ���

	return 0;
#else
	printf("Ӧ�ó��򲻼��ݴ˲���ϵͳ\n");
	getchar();
	exit(-1);
#endif
}