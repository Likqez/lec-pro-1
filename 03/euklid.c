#include <stdio.h>
//
// Created by lanzn on 05.12.2023.
//
int main_euklid() {
    int a, b;
    printf("Enter a number:");
    scanf("%d", &a);
    printf("\nEnter a number:");
    scanf("%d", &b);

    if (a * b != 0) {
        while (b != 0) {
            if (a > b)
                a -= b;
            else b -= a;
        }

        printf("solution found: %i", a);
    }

    return 0;
}
