//斐波那契数列
#include <stdio.h>
#include <windows.h>

unsigned int fac(unsigned int x)
{
	unsigned int result = 1;
	unsigned int a = 1;
	unsigned int b = 1;

	if(x > 2)
	for(unsigned int count = 2; count < x; count++)
	{
		result = (a + b);
		a = b;
		b = result;
	}

	return result;
}

int main(void)
{
	unsigned int x = 0;
	printf("请输入一个数 ");
	while(scanf("%u", &x) != 1)
	{
		printf("输入错误，请重试 ");
		while(getchar() != '\n');
	}

	printf("\n%u\n", fac(x));

	system("pause");
	return 0;
}