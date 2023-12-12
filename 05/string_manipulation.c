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
    const int dest_size = sizeof(destination) / sizeof(char);

    while (character != '\0') {
        // check if destination is full
        if (dest_size <= counter) {
            destination[counter] = '\0';
            return;
        }
        destination[counter] = character;
        counter++;
        character = source[counter];
    }
    destination[counter] = '\0';
}

void leftstr(char* target, const char* source, size_t n) {
    int counter = 0;
    char character = source[counter];
    const int target_size = sizeof(target) / sizeof(char);

    while (character != '\0') {
        if (counter == n - 1) {
            target[counter] = '\0';
            return;
        }
        // check if target is full
        if (target_size <= counter) {
            target[counter] = '\0';
            return;
        }
        target[counter] = character;
        counter++;
        character = source[counter];
    }
    target[counter] = '\0';
}

void reverstr(char* target, const char* source) {
    int lenght = 0;
    char character = source[lenght];
    const int target_size = sizeof(target) / sizeof(char);

    // count length of source
    while (character != '\0') {
        // check if target is full
        if (target_size <= lenght) break;
        lenght++;
        character = source[lenght];
    }

    // reverse source
    for (int i = lenght - 1; i >= 0; --i) {
        target[lenght - i - 1] = source[i];
    }
    target[lenght] = '\0';
}

void upstr(char* target, const char* source) {
    int counter = 0;
    char character = source[counter];
    const int target_size = sizeof(target) / sizeof(char);

    while (character != '\0') {
        if (target_size <= counter) {
            target[counter] = '\0';
            return;
        }

        if (character <= ASCII_LOWERCASE_END && character >= ASCII_LOWERCASE_START) {
            target[counter] = character - ASCII_LOWERCASE_UPPERCASE_DIFFERENCE;
        } else {
            target[counter] = character;
        }

        counter++;
        character = source[counter];
    }
}

void lowstr(char* target, const char* source) {
    int counter = 0;
    char character = source[counter];
    const int target_size = sizeof(target) / sizeof(char);

    while (character != '\0') {
        if (target_size <= counter) {
            target[counter] = '\0';
            return;
        }

        if (character <= ASCII_UPPERCASE_END && character >= ASCII_UPPERCASE_START) {
            target[counter] = character + ASCII_LOWERCASE_UPPERCASE_DIFFERENCE;
        } else {
            target[counter] = character;
        }

        counter++;
        character = source[counter];
    }
}

int main_string_mani() {
    char source[20];
    scanf("%s", &source);
    char destination[20];

    mystrcopy(destination, source);
    printf("Full copy: %s\n", destination);

    leftstr(destination, source, 3);
    printf("Left copy: %s\n", destination);

    reverstr(destination, source);
    printf("Reversed: %s\n", destination);

    upstr(destination, source);
    printf("Upper: %s\n", destination);

    lowstr(destination, source);
    printf("Lower: %s\n", destination);

    return 0;
}
