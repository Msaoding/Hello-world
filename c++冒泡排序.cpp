#include <iostream>

int main(void) {
	unsigned short int arr[] = { 4, 2, 8, 0, 5, 7, 1, 3, 9, 6};
	unsigned short int sz = sizeof(arr) / sizeof(arr[0]);

	for (unsigned short int i = 0; i < sz; i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;

	for (short int count = sz; count > 0; count--) {
		int mid = 0;
		for (unsigned short int i = 0; i < count - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				mid = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = mid;
			}
		}
	}

	std::cout << "ÅÅÐòÍê³É" << std::endl;
	for (unsigned short int i = 0; i < sz; i++) {
		std::cout << arr[i];
	}
	std::cout << std::endl;

	system("pause");
	return 0;
}