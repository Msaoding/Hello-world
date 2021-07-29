#include <stdio.h>
#include <windows.h>

void menu(void);
void choose(void);
void del(void);
float input(unsigned short int count, _Bool flag);
float _sum(void);
float _mul(void);
float _div(void);

int main(void){
    choose();

    system("pause");
    return 0;
}

void del(void){
    while (getchar() != '\n');
}

void menu(void){
    system("cls");
    printf("\n��ѡ����:\n");
    printf("a. �ӷ�                     b. �˷�\n");
    printf("c. ����                     q. �˳�\n");
}

void choose(void){
    char ch = 0;

    menu();
    while ((ch = getchar()) != 'q' && ch != 'Q'){
        switch (ch){
            case 'a':
            case 'A': printf("\nresult: %g\n", _sum()); system("pause"); break;
            case 'b':
            case 'B': printf("\nresult: %g\n", _mul()); system("pause"); break;
            case 'c':
            case 'C': printf("\nresult: %g\n", _div()); system("pause"); break;
            default: printf("��Ч���룬������\n");Sleep(1000);
        }

        del();
        menu();
    }
}

float input(unsigned short int count, _Bool flag){
    float input = 0;

    system("cls");
    printf("������� %hu ����\n", count);

    if (flag){
        while (scanf("%f", &input) != 1 || input == 0){
            printf("\n������Ч��������\n");
            del();
        }
    }
    else{
        while (scanf("%f", &input) != 1){
            printf("\n������Ч��������\n");
            del();
        }
    }

    return input;
}

float _sum(void){
    float num1 = input(1, 0);
    float num2 = input(2, 0);

    return num1 + num2;
}

float _mul(void){
    float num1 = input(1, 0);
    float num2 = input(2, 0);

    return num1 * num2;
}

float _div(void){
    float num1 = input(1, 0);
    float num2 = input(2, 1);

    return num1 / num2;
}