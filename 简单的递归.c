#include <stdio.h>
#include <windows.h>

void print(int num)					//�����������һλһλ��ӡ 			
{		
	if(num > 9)					
	print(num / 10);				
	printf("%d ", num % 10);
}

int main(void)
{
	int num = 0;

	printf("������һ���� ");
	while(scanf("%d", &num) != 1)
	while(getchar() != '\n');

	print(num);
	putchar('\n');

	system("pause");
	return 0;
}