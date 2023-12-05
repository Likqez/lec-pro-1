//
// Created by lanzn on 05.12.2023.
//

#include <stdio.h>


int input_factorial() {
    int input;
    printf("Please enter a number: ");
    scanf("%d", &input);
    printf("\n");
    return input;
}

long long calculation_factorial(const unsigned long long number, const int factor) {
    if (number == 1) return 1;
    if (factor == 1) return number;
    return calculation_factorial(number * factor, factor - 1);
}

void output_factorial(const int input, const long long value) {
    printf("%d! = %lld", input, value);
}

int main_factorial() {
    const int inputNumber = input_factorial();
    const long long result = calculation_factorial(inputNumber, inputNumber - 1);
    output_factorial(inputNumber, result);
    return 0;
}
