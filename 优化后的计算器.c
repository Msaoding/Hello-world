#include <stdio.h>
#include <windows.h>

void menu(void);
void choose(void);
void del(void);
double input(unsigned short int count, _Bool flag);
double _sum(void);
double _mul(void);
double _div(void);

int main(void) {
    choose();

    return 0;
}

void del(void) {
    while (getchar() != '\n');
}

void menu(void) {
    system("cls");
    printf("\n��ѡ����:\n");
    printf("a. �ӷ�                     b. �˷�\n");
    printf("c. ����                     q. �˳�\n");
}

void choose(void) {
    char ch = 0;

    menu();
    while ((ch = getchar()) != 'q' && ch != 'Q') {
        switch (ch) {
        case 'a':
        case 'A': printf("\nresult: %.10lg\n", _sum()); system("pause"); break;
        case 'b':
        case 'B': printf("\nresult: %.10lg\n", _mul()); system("pause"); break;
        case 'c':
        case 'C': printf("\nresult: %.10lg\n", _div()); system("pause"); break;
        default: printf("��Ч���룬������\n"); Sleep(1000); del();
        }

        menu();
    }
}

double input(unsigned short int count, _Bool flag) {
    double input = 0;

    system("cls");
    printf("������� %hu ����\n", count);

    if (flag) {
        while (scanf("%lf", &input) != 1 || input == 0) {
            printf("\n������Ч��������\n");
            del();
        }
    }
    else {
        while (scanf("%lf", &input) != 1) {
            printf("\n������Ч��������\n");
            del();
        }
    }

    del();
    return input;
}

double _sum(void) {
    double num1 = input(1, 0);
    double num2 = input(2, 0);

    return num1 + num2;
}

double _mul(void) {
    double num1 = input(1, 0);
    double num2 = input(2, 0);

    return num1 * num2;
}

double _div(void) {
    double num1 = input(1, 0);
    double num2 = input(2, 1);

    return num1 / num2;
}