//ц╟ещеепР 2021/8/7
#include <stdio.h>
#include <windows.h>
#define SZ 10

void sort(int arr[], unsigned int sz);

int main(void){
    int arr[SZ] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (unsigned int i = 0; i < SZ; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    sort(arr, SZ);

    for (unsigned int i = 0; i < SZ; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');

    system("pause");
    return 0;
}

void sort (int arr[], unsigned int sz){
    for (unsigned int count = sz; count > 0; count--){
        for (unsigned int i = 0; i < count; i++){
            int* ptr = arr;

            if (*(ptr + i) > *(ptr + 1 + i)){
                *(ptr + i) ^= *(ptr + 1 + i);
                *(ptr + 1 + i) ^= *(ptr + i);
                *(ptr + i) ^= *(ptr + 1 + i);
            }
        }
    }

    return;
}