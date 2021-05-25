#include <iostream>

void swap(unsigned short int sz, int arr[]) {
	unsigned short int count = sz / 2;
	for (unsigned short int i = 1; i <= count; i++) {
		int start = i - 1;
		int end = sz - i;
		int mid = 0;

		mid = arr[start];
		arr[start] = arr[end];
		arr[end] = mid;
	}
}

int main(void) {
	int arr[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	unsigned short int sz = sizeof(arr) / sizeof(arr[0]);
	for (unsigned short int i = 0; i < sz; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;

	swap(sz, arr);

	for (unsigned short int i = 0; i < sz; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}