//
// Created by lanzn on 11.12.2023.
//
#include <stdio.h>

// useless only test :)
int main_euklid_ptr() {
    int a,b;
    int * a_ptr = &a, *b_ptr = &b;
    printf("Enter a number:");
    scanf("%d", a_ptr);
    printf("\nEnter a number:");
    scanf("%d", b_ptr);

    if (*a_ptr * *b_ptr != 0) {
        while (*b_ptr != 0) {
            if (*a_ptr > *b_ptr)
                *a_ptr -= *b_ptr;
            else *b_ptr -= *a_ptr;
        }

        printf("solution found: %i", *a_ptr);
    }

    return 0;
}
