#include <stdio.h>
#include <windows.h>

void binary(unsigned int);

int main(void){
    unsigned int num = 0;

    printf("二进制转换\n");
    while (scanf("%u", &num) == 1){
        while (getchar() != '\n');
        binary(num);
    }

    system("pause");
    return 0;
}

void binary(unsigned int num){
    if (num){
        printf("%u", (num % 2));
        binary(num /= 2);
    }

    putchar('\n');
    return;
}