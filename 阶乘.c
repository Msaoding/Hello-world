//�׳�
#include <stdio.h>
#include <windows.h>

unsigned int jiecheng(unsigned int x)
{
	static unsigned int count = 1;
	static unsigned int result = 1;

	if(count < x)
	{
		result *= ++count;
		jiecheng(x);
	}
	else return result;
}

int main(void)
{
	unsigned int x = 0;

	printf("������һ����	");
	while(scanf("%u", &x) != 1)
	{
		printf("�������������	");
		while(getchar() != '\n');
	}

	printf("\n%u\n", jiecheng(x));

	system("pause");
	return 0;
}