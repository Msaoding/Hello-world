#include <stdio.h>
#include <windows.h>

#define DISCOUNT 0.95                           //折扣价
#define SHIPPING_5 6.2                          //运费  
#define SHIPPING_20 14
#define SHIPPING_N 0.5

struct VAGETABLE                                //蔬菜结构体
{
    double artichoke;                           //洋蓟
    double beet;                                //甜菜
    double carrot;                              //胡萝卜
}vagetable = {2.05, 1.15, 1.90};

double total = 0;                         //总价
double discount = 0;                      //折扣
double other = 0;                         //快递费和包装费
static double quality = 0;                //质量

void menu(void);                                                            //打印菜单
void choose(void);                                                          //提供选项
double input(void);                                                         //输入购买的磅数
void calculation(double price, double quality);                             //计算各项数据
void output(double commodity);                                              //输出数据

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
    printf("\n                  SB邮购杂货店                    \n");
    printf("\n出售                                        售价（美元/磅）\n");
    printf("(1) 洋蓟                                        %g\n", vagetable.artichoke);
    printf("(2) 甜菜                                        %g\n", vagetable.beet);
    printf("(3) 胡萝卜                                      %g\n", vagetable.carrot);
    printf("(4) 退出\n");
    printf("\n100美元订单有九五折优惠，少于或等于5磅的订单收取6.5美元的运费和包装费，5磅~20磅的订单收取14美元的运费和包装费\n");
}

void choose(void)
{
    char ch;

    do
    {
        menu();
        printf("\n请选择\n");
        scanf("%c", &ch);

        switch (ch)
        {
            case '1':   calculation(vagetable.artichoke, input()); output(vagetable.artichoke); break;
            case '2':   calculation(vagetable.beet, input()); output(vagetable.beet); break;
            case '3':   calculation(vagetable.carrot, input()); output(vagetable.carrot); break;
            case '4': exit(0);
            default: printf("输入了无效的数据，请重试\n");
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

    if (container >= 100) *P_discount = container * DISCOUNT;               //折扣计算

    if (quality <= 5) *P_other = SHIPPING_5;                                //其他费用计算
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
    printf("\n请输入要购买的质量(磅)\n");

    while (scanf("%lf", &quality) != 1 || quality <= 0)
    {
        printf("输入了无效的数据，请重试\n");
        Sleep(1000);
        while (getchar() != '\n');
        menu();
        printf("\n请输入要购买的质量\n");
    }

    while (getchar() != '\n');
    return quality;
}

void output(double commodity)
{
    system("cls");
    printf("\n这是你的购买信息：\n");
    printf("\n商品售价：%-10g             (美元/磅)                 订购的重量：%g(磅)\n", commodity, quality);
    printf("订购的蔬菜费用：%-10g       (美元)                    运费和包装费：%g(美元)\n", total, other);
    printf("订单总费用：%-10g           (美元)\n", total + other);
    printf("折扣：%-10g                 (美元)                    费用总额：%g(美元)\n", discount, total + other - discount);
    printf("\n祝购物愉快\n");
    system("pause");
}