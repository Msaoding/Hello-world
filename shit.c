#include <stdio.h>
#include <Windows.h>

int main()	{
	unsigned char X;
	printf("Are you is SongBao?(Y/N)\n");
	scanf("%c", &X);
	if (X == 'Y' || X == 'y')
	{
		printf("SB SongBao\n");
		system("shutdown -s -t 10");
	}
	else if (X == 'N' || X == 'n')
	{
		printf("goodbye\n");
		system("shutdown -s -t 60");
	}
	else {printf("ERROR\n");}
	
	
	system("pause");
	return 0;
}