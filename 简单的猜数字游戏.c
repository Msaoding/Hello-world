#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void menu(unsigned int num);
void choose(unsigned int num);


int main(void){
    srand((unsigned int)time(NULL));
    unsigned int num;

    num = rand() % MAX;
    choose (num);

    system("pause");
    return 0;
}

void menu(unsigned int num){
    system("cls");
    printf("\n猜数字: %u\n", num);
    printf("Y 正确      S 小了     D 大了     Q 退出\n");
}

void choose(unsigned int num){
    char ch = 0;
    unsigned int max = MAX;
    unsigned int min = 0;

    menu(num);
    while (((ch = getchar()) != 'Q') && (ch != 'q')){

        switch (ch){
            case 'y':
            case 'Y': printf("\n猜对了！\n"); max = MAX; min = 0; num = rand() % MAX; Sleep(1000); break;
            case 's':
            case 'S': min = num; num = (min + max) / 2; break;
            case 'd':
            case 'D': max = num; num = (min + max) / 2; break;
            default: printf("\n输入无效\n");
                     Sleep(1000);
        }

        while (getchar() != '\n');
        menu(num);
    }
}