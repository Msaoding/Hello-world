//Çî¾Ù·¨²éÕÒ×Ö·û´®  2024.1.24
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include <time.h>

char* serch_string(const char* arr, const char* str);

int main(void) {
    FILE* file = fopen("test.txt", "r");
    char arr[1024] = { 0 };
    fread(arr, 1, 1024, file);

    printf("%s\n", serch_string(arr, "tlwhcqjf"));

    fclose(file);
    system("pause");
    return 0;
}

char* serch_string(const char* arr, const char* str) {
    assert(arr);
    assert(str);
    const char* parr = arr;
    const char* pstr = str;
    const char* tmp = arr;

    while (*parr) {
        Sleep(1);
        if (*parr == *pstr) {
            parr++;
            pstr++;
        }
        else {
            tmp++;
            parr = tmp;
            pstr = str;
        }

        if (*pstr == 0) {
            return (char*)tmp;
        }
    }

    return NULL;
}