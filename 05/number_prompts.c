#include <stdio.h>
//
// Created by lanzn on 12.12.2023.
//
int action;

void promptAction() {
    printf("(1) Calculate the Power\n");
    printf("(2) Binary Conversion\n");
    printf("(3) Exit\n");
    printf("What do you want to do? ");

    scanf("%d", &action);
}

void convert_to_binary_prompt_calc(int decimal_number) {
    if (decimal_number != 0) {
        convert_to_binary_prompt_calc(decimal_number / 2);
        printf("%i", decimal_number % 2);
    }
}

double power_of_prompt_calc(int basis, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent > 0) {
        return basis * power_of_prompt_calc(basis, exponent - 1);
    }
    return 1 / power_of_prompt_calc(basis, -exponent);
}

int main_prompts() {
    promptAction();

    while (action != 3) {
        switch (action) {
            case 2: {
                int input;
                printf("Enter a number:");
                scanf("%i", &input);
                convert_to_binary_prompt_calc(input);
                printf("\n");
                break;
            }
            case 1: {
                int base, exponent;
                printf("Base:");
                scanf("%i", &base);
                printf("Expo:");
                scanf("%i", &exponent);
                const double result = power_of_prompt_calc(base, exponent);
                printf("Result: %f\n", result);
                break;
            }
            default: return 0;
        }
        promptAction();
    }
    return 0;
}
