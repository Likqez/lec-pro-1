#include <stdio.h>
//
// Created by lanzn on 05.12.2023.
//
#define UPPER_BOUND 10

// print the header
void header() {
    printf("\t\t\t******The small multuplication table ******\n");
    for (int i = 0; i <= UPPER_BOUND; ++i) {
        if (i == 0) {
            printf("\t");
            continue;
        }
        printf("%d \t", i);
    }

    printf("\n");
    for (int i = 0; i <= UPPER_BOUND; ++i) {
        printf("--------");
    }
    printf("\n");
}

// calculate and print the body
void body() {
    for (int i = 1; i <= UPPER_BOUND; ++i) {
        // print row identifier
        printf("%02d    |\t", i);

        for (int j = 1; j <= UPPER_BOUND; ++j) {
            printf("%d \t", i*j);
            if(j == UPPER_BOUND) {
                printf("\n");
            }
        }
    }
}

int main_multi() {
    header();
    body();
    return 0;
}
