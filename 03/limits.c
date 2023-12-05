#include "../../../AppData/Local/Programs/CLion Nova/bin/mingw/x86_64-w64-mingw32/include/limits.h"

#include <limits.h>
#include <stdio.h>
//
// Created by lanzn on 05.12.2023.
//
// Print table of datatypes and their limits
int main_limits() {
    printf("Type \t len \t MIN \t\t\t MAX\n");

    printf("Char \t %d \t %d \t\t\t %d\n",SCHAR_WIDTH,SCHAR_MIN, SCHAR_MAX);
    printf("UChar \t %d \t %d \t\t\t %d\n",UCHAR_WIDTH, 0, UCHAR_MAX);

    printf("Short \t %d \t %d \t\t %d\n",SHRT_WIDTH,SHRT_MIN, SHRT_MAX);
    printf("UShort \t %d \t %d \t\t\t %d\n",USHRT_WIDTH, 0, USHRT_MAX);

    printf("Int \t %d \t %d \t\t %d\n",INT_WIDTH,INT_MIN, INT_MAX);
    printf("UInt \t %d \t %d \t\t\t %d\n",UINT_WIDTH, 0, UINT_MAX);

    printf("Long \t %d \t %lld \t\t %lld\n",LONG_WIDTH,LONG_MIN, LONG_MAX);
    printf("ULong \t %d \t %d \t\t\t %lld\n",ULONG_WIDTH, 0, ULONG_MAX);

    printf("LLong \t %d \t %lld \t %lld\n",LLONG_WIDTH,LONG_LONG_MIN, LONG_LONG_MAX);
    printf("ULLong \t %d \t %d \t %lld\n",ULLONG_WIDTH, 0, ULONG_LONG_MAX);
    return 0;
}
