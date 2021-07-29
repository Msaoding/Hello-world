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
    printf("\n请选择功能:\n");
    printf("a. 加法                     b. 乘法\n");
    printf("c. 除法                     q. 退出\n");
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
            default: printf("无效输入，请重试\n");Sleep(1000);
        }

        del();
        menu();
    }
}

float input(unsigned short int count, _Bool flag){
    float input = 0;

    system("cls");
    printf("请输入第 %hu 个数\n", count);

    if (flag){
        while (scanf("%f", &input) != 1 || input == 0){
            printf("\n输入无效，请重试\n");
            del();
        }
    }
    else{
        while (scanf("%f", &input) != 1){
            printf("\n输入无效，请重试\n");
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