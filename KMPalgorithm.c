//实现KMP算法   2024.1.24
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <assert.h>

#define SZ 2000

char* kmp_serch(const char* arr, const char* dest);
char* build_next(const char dest[], size_t sz);

int main(void) {
    FILE* file = fopen64("test.txt", "r");
    char arr[SZ + 24] = { 0 };
    fread(arr, 1, (size_t)SZ, file);

    printf("%s\n", kmp_serch(arr, "The string to search for"));

    fclose(file);
    system("pause");
    return 0;
}

char* kmp_serch(const char* arr, const char* dest) {
    assert(arr);
    assert(dest);

    size_t length = strlen(dest);
    char* next = build_next(dest, length);
    unsigned int i = 0;
    unsigned int j = 0;

    do {
        while (arr[i] == dest[j] && arr[i]) {
            i++;
            j++;
        }

        if (dest[j] == 0) {
            free(next);
            return (char*)&arr[i - length];
        }
        else if (j != 0){
            j = next[j - 1];
        }
        else {
            i++;
        }
    } while (arr[i]);

    free(next);
    return NULL;
}

char* build_next(const char dest[], size_t sz) {
    char* next = (char*)malloc(sz);
    unsigned int i = 1;
    unsigned int j = 0;
    unsigned int width = 0;

    if (next == NULL) {
        return NULL;
    }
    next[0] = 0;

    for (; i < sz; i++) {
        if (dest[j] == dest[i]) {
            next[i] = ++width;
            j++;
        }
        else if (i > 1 && j > 0) {
            j = next[j - 1];
            j = 0;
            width = 0;
            next[i] = 0;
        }
        else {
            next[i] = 0;
        }
    }

    return next;
}