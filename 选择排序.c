//—°‘Ò≈≈–Ú 2021/9/27
#include <stdio.h>
#include <windows.h>

void select_sort(int*, const unsigned);

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (unsigned i = 0; i < 10; i++)
    {
        printf("%-3d", arr[i]);
    }
    select_sort(arr, 10);
    putchar('\n');
    for (unsigned i = 0; i < 10; i++)
    {
        printf("%-3d", arr[i]);
    }

    getchar();
    return 0;
}

void select_sort(int* arr, const unsigned sz)
{
    for (unsigned i = 0; i < sz - 1; i++)
    {
        int max = i;

        for (unsigned j = (i + 1); j < sz; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }

        if (max != i)
        {
            arr[i] ^= arr[max];
            arr[max] ^= arr[i];
            arr[i] ^= arr[max];
        }
    }
    return;
}