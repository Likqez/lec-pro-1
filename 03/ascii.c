#include <ctype.h>
#include <stdio.h>
//
// Created by lanzn on 05.12.2023.
//
int main_ascii() {
    // Get the user input.
    printf("Enter a number or character:");
    char input;
    input = scanf("%c", &input);

    // Output the char and the input formatted to a digit
    printf("\nThe ASCII code for '%c' is %d.\n", input, input);

    return 0;
}
