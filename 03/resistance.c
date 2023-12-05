#include <stdio.h>
//
// Created by lanzn on 05.12.2023.
//
float input_resistance(char text[]) {
    printf("%s", text);
    float input;
    scanf("%f", &input);
    printf("\n");
    return input;
}

int main_resistance() {
    // Ask for Resistance of 2 resitors
    const float r1 = input_resistance("Enter resitance of resistor 1:");
    const float r2 = input_resistance("Enter resitance of resistor 2:");

    // calculate total resistnace
    const float total_resistance = 1 / (1 / r1 + 1 / r2);

    printf("The total resistance is %.4E", total_resistance);

    return 0;
}
