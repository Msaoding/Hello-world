//ͳ�ƶ�������1�ĸ��� 2021/8/8
#include <stdio.h>
#include <windows.h>

unsigned short int count(unsigned int num);

int main(void){
    int num = 0;

    printf("ͳ�ƶ�������1�ĸ�����\n�����룺 ");
    while (scanf("%d", &num) != 1){
        printf("�������������\n");
        while (getchar() != '\n');
        Sleep(1000);
        system("cls");
        printf("ͳ�ƶ�������1�ĸ�����\n�����룺 ");
    }

    printf("%d �ڶ��������� %hu ��1\n", num, count(num));

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