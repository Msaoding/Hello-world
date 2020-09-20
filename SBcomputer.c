#include <stdio.h>
#include <Windows.h>

int main (void)
{
	char C;			//注意区分大小写 
	char c;			//第一次选择是C第二次选择是c 
	float x, y;
	
	printf("欢迎使用智障计算器\n");
	printf("请选择功能(A:加法 B:减法 C:乘法 D:除法)\n");
	scanf("%c", &C);
	getchar();
	if (C == 'a' || C == 'A')								//选择判断 
	{
		printf("你选择的是加法?(Y/N)");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("请输入x的值\n");						//计算部分 
			scanf("%f", &x);
			printf("请输入y的值\n");
			scanf("%f", &y);
			printf("x+y的结果为 %.2f \n", x + y);
		}
	}
	else if (C == 'b' || C == 'B')
	{
		printf("你选择的是减法？(Y/N)");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("请输入x的值\n");
			scanf("%f", &x);
			printf("请输入y的值\n");
			scanf("%f", &y);
			printf("x-y的结果为 %.2f \n", x - y);
		}
	}
	else if (C == 'c' || C == 'C')
	{
		printf("你选择的是乘法(Y/N)\n");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("请输入x的值\n");
			scanf("%f", &x);
			printf("请输入y的值\n");
			scanf("%f", &y);
			printf("x*y的结果为 %.2f \n", x * y);
		}
	}
	else if (C == 'd' || C == 'D')
	{
		printf("你选择的是除法(Y/N)\n");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("请输入x的值\n");
			scanf("%f", &x);
			printf("请输入y的值\n");
			scanf("%f", &y);
			printf("x / y的结果为 %.2f \n", x / y);
		}
	}
	else {printf("ERROR\n");}
	
	system ("pause");
	return 0;
}
