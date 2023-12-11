#include <stdio.h>
//
// Created by lanzn on 05.12.2023.
//
#define UPPER_BOUND 10

int matrix[UPPER_BOUND][UPPER_BOUND];

// print the header
void header_multi() {
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

void calculate_multi() {
    for (int i = 1; i <= UPPER_BOUND; ++i) {
        for (int j = 1; j <= UPPER_BOUND; ++j) {
            matrix[i-1][j-1] = i*j;
        }
    }
}

//  print the body
void body_mutli() {
    for (int i = 1; i <= UPPER_BOUND; ++i) {
        // print row identifier
        printf("%02d    |\t", i);

        for (int j = 1; j <= UPPER_BOUND; ++j) {
            printf("%d \t", matrix[i-1][j-1]);
            if(j == UPPER_BOUND) {
                printf("\n");
            }
        }
    }
}

int main_multi_arr() {
    calculate_multi();
    header_multi();
    body_mutli();
    return 0;
}
