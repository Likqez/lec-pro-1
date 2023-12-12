//
// Created by lanzn on 12.12.2023.
//

#include <stdio.h>

#define ASCII_LOWERCASE_UPPERCASE_DIFFERENCE 32
#define ASCII_LOWERCASE_START 97
#define ASCII_LOWERCASE_END 122
#define ASCII_UPPERCASE_START 65
#define ASCII_UPPERCASE_END 90

void mystrcopy(char destination[], char source[]) {
    int counter = 0;
    char character = source[counter];

    while (character != '\0') {
        destination[counter] = character;
        counter++;
        character = source[counter];
    }
}

void leftstr(char * target, const char * source, size_t n) {
    int counter = 0;
    char character = source[counter];

    while (character != '\0') {
        if(counter == n) {
            target[counter] = '\0';
            return;
        }
        target[counter] = character;
        counter++;
        character = source[counter];
    }
}

void reverstr(char * target, const char * source) {
    int lenght = 0;
    char character = source[lenght];

    // count length of source
    while (character != '\0') {
        lenght++;
        character = source[lenght];
    }

    // reverse source
    for (int i = lenght - 1; i >= 0; --i) {
        target[lenght - i - 1] = source[i];
    }
}

void upstr(char * target, const char * source) {
    int counter = 0;
    char character = source[counter];

    while (character != '\0') {

        if(character <= ASCII_LOWERCASE_END && character >= ASCII_LOWERCASE_START) {
            target[counter] = character - ASCII_LOWERCASE_UPPERCASE_DIFFERENCE;
        } else {
            target[counter] = character;
        }

        counter++;
        character = source[counter];
    }
}

void lowstr(char * target, const char * source) {
    int counter = 0;
    char character = source[counter];

    while (character != '\0') {

        if(character <= ASCII_UPPERCASE_END && character >= ASCII_UPPERCASE_START) {
            target[counter] = character + ASCII_LOWERCASE_UPPERCASE_DIFFERENCE;
        } else {
            target[counter] = character;
        }

        counter++;
        character = source[counter];
    }
}

int main() {
    char source[] = "Hello World";
    char destination[20];

    mystrcopy(destination,source);
    printf("Full copy: %s\n", destination);

    leftstr(destination,source, 3);
    printf("Left copy: %s\n", destination);

    reverstr(destination,source);
    printf("Reversed: %s\n", destination);

    upstr(destination,source);
    printf("Upper: %s\n", destination);

    lowstr(destination,source);
    printf("Lower: %s\n", destination);

    return 0;
}
