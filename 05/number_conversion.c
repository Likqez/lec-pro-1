//
// Created by lanzn on 12.12.2023.
//

#include <stdio.h>

void convert_to_binary(int decimal_number);

int main_conversion() {
    int input;
    printf("Enter a number:");
    scanf("%i", &input);
    convert_to_binary(input);
    return 0;
}

void convert_to_binary(int decimal_number) {
    if (decimal_number != 0) {
        convert_to_binary(decimal_number/2);
        printf("%i", decimal_number % 2);
    }
}
