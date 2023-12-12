#include <stdio.h>
//
// Created by lanzn on 12.12.2023.
//
double power_of(int basis, int exponent);

int main_power_of() {
    int base, exponent;
    printf("Base:");
    scanf("%i", &base);
    printf("Expo:");
    scanf("%i", &exponent);
    const double result = power_of(base, exponent);
    printf("%f", result);
    return 0;
}

double power_of(int basis, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent > 0) {
        return basis * power_of(basis, exponent - 1);
    }
    return 1 / power_of(basis, -exponent);
}
