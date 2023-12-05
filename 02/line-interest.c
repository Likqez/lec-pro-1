//
// Created by lanzn on 04.12.2023.
//
#include <stdio.h>

void lines() {
    printf("line1\nline2\nline3\nlast line");
}

void interest(float basecapital) {
    float cap = basecapital;

    for (int i = 1; i <= 10; ++i) {
        cap = cap * 1.034;
        printf("year: \t%d \t capital: %.2f\n", i, cap);
    }
    printf("\n");

    printf(
        "you can achieve %.2f EUR of you base capital of %.2f EUR with an interest rate of 3.4%% per year in 10 years",
        cap, basecapital);
}

int main_line() {
    lines();
    printf("\n\n");
    interest(1000);
    return 0;
}