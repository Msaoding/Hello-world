#include <stdio.h>
#include <windows.h>

void sort(int arr[], unsigned short int sz)				//冒泡排序
{
	for(unsigned short int i = 0; i < sz; i++)
	{
		int* num1 = &arr[i];
		int* num2 = &arr[i + 1];
		int mid = 0;

		if(*num1 > *num2)
		{
			mid = *num1;
			*num1 = *num2;
			*num2 = mid;
		}
	}
}

short int search(int arr[], int num, unsigned short int sz)			//二分查找
{
	int low = 0;
	int hight = --sz;
	int mid = (hight + low) / 2;

	while(hight >= low && ((arr[low]) <= num && (arr[hight] >= num)))
	{
		if(arr[mid] > num)
		hight = mid;
		else if(arr[mid] < num)
		low = ++mid;
		else return mid;
		mid = (hight + low) / 2;
	}
	return -1;
}

int main(void)
{
	int num = 0;
	int arr[10] = {4, 1, 2, 3, 7, 5, 6, 8, 10, 9};
	unsigned short int sz = (unsigned short int)sizeof(arr) / (unsigned short int)sizeof(arr[0]);
	short int result = 0;

	sort(arr, sz);
	for(unsigned short int i = 0; i < 10; i++)
	printf("%d ", arr[i]);
	putchar('\n');

	printf("请输入你要查找的数 ");
	while(scanf("%d", &num) != 1)
	{
		while(getchar() != '\n');
		printf("输入错误，请重试 ");
	}

	result = search(arr, num, sz);
	if(result + 1)
	printf("你要查找的数 %d 在 arr[%d]", num, result);
	else printf("找不到\n");

	system("pause");
	return 0;
}