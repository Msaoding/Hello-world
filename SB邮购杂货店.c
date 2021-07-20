#include <stdio.h>
#include <windows.h>

#define DISCOUNT 0.95                           //�ۿۼ�
#define SHIPPING_5 6.2                          //�˷�  
#define SHIPPING_20 14
#define SHIPPING_N 0.5

struct VAGETABLE                                //�߲˽ṹ��
{
    double artichoke;                           //��
    double beet;                                //���
    double carrot;                              //���ܲ�
}vagetable = {2.05, 1.15, 1.90};

double total = 0;                         //�ܼ�
double discount = 0;                      //�ۿ�
double other = 0;                         //��ݷѺͰ�װ��
static double quality = 0;                //����

void menu(void);                                                            //��ӡ�˵�
void choose(void);                                                          //�ṩѡ��
double input(void);                                                         //���빺��İ���
void calculation(double price, double quality);                             //�����������
void output(double commodity);                                              //�������

int main(void)
{
    //menu();
    //input();
    choose();

    system("pause");
    return 0;
}

void menu(void)
{
    system("cls");
    printf("\n                  SB�ʹ��ӻ���                    \n");
    printf("\n����                                        �ۼۣ���Ԫ/����\n");
    printf("(1) ��                                        %g\n", vagetable.artichoke);
    printf("(2) ���                                        %g\n", vagetable.beet);
    printf("(3) ���ܲ�                                      %g\n", vagetable.carrot);
    printf("(4) �˳�\n");
    printf("\n100��Ԫ�����о������Żݣ����ڻ����5���Ķ�����ȡ6.5��Ԫ���˷ѺͰ�װ�ѣ�5��~20���Ķ�����ȡ14��Ԫ���˷ѺͰ�װ��\n");
}

void choose(void)
{
    char ch;

    do
    {
        menu();
        printf("\n��ѡ��\n");
        scanf("%c", &ch);

        switch (ch)
        {
            case '1':   calculation(vagetable.artichoke, input()); output(vagetable.artichoke); break;
            case '2':   calculation(vagetable.beet, input()); output(vagetable.beet); break;
            case '3':   calculation(vagetable.carrot, input()); output(vagetable.carrot); break;
            case '4': exit(0);
            default: printf("��������Ч�����ݣ�������\n");
                     while (getchar() != '\n');
                     Sleep(1000);
        }
    }while (1);
}

void calculation(double price, double quality)
{
    double* P_total = &total;
    double* P_discount = &discount;
    double* P_other = &other;

    double container = *P_total = (price * quality);

    if (container >= 100) *P_discount = container * DISCOUNT;               //�ۿۼ���

    if (quality <= 5) *P_other = SHIPPING_5;                                //�������ü���
    else if (quality > 5 && quality <= 20)  *P_other = SHIPPING_20;
    else if (quality > 20)
    {
        quality -= 20;
        *P_other = quality * SHIPPING_N + SHIPPING_20;
    }
}

double input(void)
{
    while (getchar() != '\n');
    //system("cls");
    printf("\n������Ҫ���������(��)\n");

    while (scanf("%lf", &quality) != 1 || quality <= 0)
    {
        printf("��������Ч�����ݣ�������\n");
        Sleep(1000);
        while (getchar() != '\n');
        menu();
        printf("\n������Ҫ���������\n");
    }

    while (getchar() != '\n');
    return quality;
}

void output(double commodity)
{
    system("cls");
    printf("\n������Ĺ�����Ϣ��\n");
    printf("\n��Ʒ�ۼۣ�%-10g             (��Ԫ/��)                 ������������%g(��)\n", commodity, quality);
    printf("�������߲˷��ã�%-10g       (��Ԫ)                    �˷ѺͰ�װ�ѣ�%g(��Ԫ)\n", total, other);
    printf("�����ܷ��ã�%-10g           (��Ԫ)\n", total + other);
    printf("�ۿۣ�%-10g                 (��Ԫ)                    �����ܶ%g(��Ԫ)\n", discount, total + other - discount);
    printf("\nף�������\n");
    system("pause");
}