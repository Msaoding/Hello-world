//统计二进制中1的个数 2021/8/8
#include <stdio.h>
#include <windows.h>

unsigned short int count(unsigned int num);

int main(void){
    int num = 0;

    printf("统计二进制中1的个数：\n请输入： ");
    while (scanf("%d", &num) != 1){
        printf("输入错误，请重试\n");
        while (getchar() != '\n');
        Sleep(1000);
        system("cls");
        printf("统计二进制中1的个数：\n请输入： ");
    }

    printf("%d 在二进制中有 %hu 个1\n", num, count(num));

    system("pause");
    return 0;
}

unsigned short int count(unsigned int num){
    unsigned short int result = 0;

        while (num){
        if (num % 2){
                result++;
            }
            num /= 2;
        }

    return result;
}