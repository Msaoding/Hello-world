#include <stdio.h>
#include <Windows.h>

int main (void)
{
	char C;			//ע�����ִ�Сд 
	char c;			//��һ��ѡ����C�ڶ���ѡ����c 
	float x, y;
	
	printf("��ӭʹ�����ϼ�����\n");
	printf("��ѡ����(A:�ӷ� B:���� C:�˷� D:����)\n");
	scanf("%c", &C);
	getchar();
	if (C == 'a' || C == 'A')								//ѡ���ж� 
	{
		printf("��ѡ����Ǽӷ�?(Y/N)");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("������x��ֵ\n");						//���㲿�� 
			scanf("%f", &x);
			printf("������y��ֵ\n");
			scanf("%f", &y);
			printf("x+y�Ľ��Ϊ %.2f \n", x + y);
		}
	}
	else if (C == 'b' || C == 'B')
	{
		printf("��ѡ����Ǽ�����(Y/N)");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("������x��ֵ\n");
			scanf("%f", &x);
			printf("������y��ֵ\n");
			scanf("%f", &y);
			printf("x-y�Ľ��Ϊ %.2f \n", x - y);
		}
	}
	else if (C == 'c' || C == 'C')
	{
		printf("��ѡ����ǳ˷�(Y/N)\n");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("������x��ֵ\n");
			scanf("%f", &x);
			printf("������y��ֵ\n");
			scanf("%f", &y);
			printf("x*y�Ľ��Ϊ %.2f \n", x * y);
		}
	}
	else if (C == 'd' || C == 'D')
	{
		printf("��ѡ����ǳ���(Y/N)\n");
		scanf("%c", &c);
		if (c == 'y' || c == 'Y')
		{
			printf("������x��ֵ\n");
			scanf("%f", &x);
			printf("������y��ֵ\n");
			scanf("%f", &y);
			printf("x / y�Ľ��Ϊ %.2f \n", x / y);
		}
	}
	else {printf("ERROR\n");}
	
	system ("pause");
	return 0;
}
