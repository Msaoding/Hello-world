#include <stdio.h>
#include <windows.h>

void print(int num)					//将输入的数拆开一位一位打印 			
{		
	if(num > 9)					
	print(num / 10);				
	printf("%d ", num % 10);
}

int main(void)
{
	int num = 0;

	printf("请输入一个数 ");
	while(scanf("%d", &num) != 1)
	while(getchar() != '\n');

	print(num);
	putchar('\n');

	system("pause");
	return 0;
}