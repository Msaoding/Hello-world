#include <stdio.h>
#include <windows.h>

short int search(int arr[], unsigned short int max, unsigned short int min, int num)
{
	unsigned short int mid = (max + min) / 2;
	while (max >= min)
	{
		if (arr[mid] > num)
			max = mid;
		else if (arr[mid] < num)
			min = ++mid;
		else
			return mid;
		mid = (max + min) / 2;
	}
	return -1;
}

int main(void)
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int num = 0;
	printf("请输入你要查找的数字 ");
	scanf("%d", &num);
	printf("\n%hd\n", search(arr, 9, 0, num));

	system("pause");
	return 0;
}