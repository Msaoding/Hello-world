#include <stdio.h>
#include <windows.h>

_Bool choose = 1;

void sort(int arr[], unsigned int sz){
    for (unsigned int count = 0; count < (sz - 1); count++){         //9
        for (unsigned int i = 0; i < (sz - 1 - count); i++){
                if (arr[i] > arr[i + 1]){
                int md = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = md;
                choose = 0;
            }
                else{
                    choose = 1;
                }
        }
        if (choose){
            printf("进行了%u遍排序\n", count + 1);
            break;
        }
        printf("进行了%u遍排序\n", count + 1);
    }
}

int main(void){
    int arr[] = {1, 2, 4, 3, 6, 5, 7, 8, 9, 10,};
    unsigned int sz = sizeof(arr) / sizeof(arr[0]);
    for (unsigned short int i = 0; i < sz; i++){
        printf("%4d", arr[i]);
    }
    putchar('\n');
    sort(arr, sz);
    for (unsigned short int i = 0; i < sz; i++){
        printf("%4d", arr[i]);
    }
    putchar('\n');

    system("pause");
    return 0;
}