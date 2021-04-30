#include <iostream>
#include <cstdlib>
#include <cmath>

using std::endl;
using std::cin;
using std::cout;

void flower(int num) {
	if (num >= 100 && num <= 1000) {
		int num1 = num / 100;
		int num2 = num / 10 % 10;
		int num3 = num % 10;

		if ((pow(num1, 3) + pow(num2, 3) + pow(num3 , 3)) == num)
			cout << num << "是水仙花数" << endl;
	}
}

int main(void) {
	int i = 100;
	do {
		flower(i);
		i++;
	} while (i < 1000);

	system("pause");
	return 0;
}