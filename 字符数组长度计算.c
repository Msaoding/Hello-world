#include <stdio.h>
#include <windows.h>

unsigned short int mystrlen(char* arr)
{
	static unsigned short int count = 0;
	if(*arr != '\0')
	{
		count++;
		mystrlen(++arr);
	}
	return (count);
}

int main(void)
{
	char arr[] = "msaoding";
	unsigned short int len = mystrlen(arr);
	printf("%d\n", len);

	system("pause");
	return 0;
}