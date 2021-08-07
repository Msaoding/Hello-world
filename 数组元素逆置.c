//Êı×éÔªËØÄæÖÃ 2021/8/7
#include <stdio.h>
#include <windows.h>
#define SZ 10

int* initarr(void);
void re(int* ptr, unsigned int sz);

int main(void){
    int* ptr = initarr();

    for (unsigned int i = 0; i < SZ; i++){
        printf("%d ", ptr[i]);
    }
    putchar('\n');

    re(ptr, SZ);

    for (unsigned int i = 0; i < SZ; i++){
        printf("%d ", ptr[i]);
    }
    putchar('\n');

    system("pause");
    return 0;
}

int* initarr(void){
    static int arr[SZ] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    return arr;
}

void re(int* ptr, unsigned int sz){
    unsigned int count = sz / 2 + sz % 2;

    for (unsigned int i = 0; i < count; i++){
        ptr[i] ^= ptr[sz - 1 - i];
        ptr[sz - 1 - i] ^= ptr[i];
        ptr[i] ^= ptr[sz - 1 - i];
    }
    return;
}