//斐波那契数列
#include <stdio.h>
#include <windows.h>

unsigned int fac(unsigned int x)
{
	unsigned int result = 1;

	if(x <= 2)
	return result;
	else
	return result = (fac(x - 1) + fac(x - 2));
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