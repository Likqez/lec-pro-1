#include <stdio.h>
#include <stdlib.h>
//
// Created by lanzn on 05.12.2023.
//
#define UPPER_BOUND 10

//int matrixarr[UPPER_BOUND][UPPER_BOUND];
//int * matrix_ptr = &matrixarr[0][0];
int * matrix_ptr;

// print the header
void header_multi_ptr() {
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

void calculate_multi_ptr() {
    for (int i = 1; i <= UPPER_BOUND; ++i) {
        for (int j = 1; j <= UPPER_BOUND; ++j) {
            *(matrix_ptr + (i-1) * UPPER_BOUND + (j-1)) = i * j;
        }
    }
}

//  print the body
void body_mutli_ptr() {
    for (int i = 1; i <= UPPER_BOUND; ++i) {
        // print row identifier
        printf("%02d    |\t", i);

        for (int j = 1; j <= UPPER_BOUND; ++j) {
            printf("%d \t", *(matrix_ptr + (i-1) * UPPER_BOUND + (j-1)));
            if(j == UPPER_BOUND) {
                printf("\n");
            }
        }
    }
}

int main_multi_arr_ptr() {
    matrix_ptr = malloc(UPPER_BOUND * UPPER_BOUND * sizeof(int));
    calculate_multi_ptr();
    header_multi_ptr();
    body_mutli_ptr();
    return 0;
}
