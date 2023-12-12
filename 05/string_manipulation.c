//
// Created by lanzn on 12.12.2023.
//

#include <stdio.h>

#define ASCII_LOWERCASE_UPPERCASE_DIFFERENCE 32
#define ASCII_LOWERCASE_START 97
#define ASCII_LOWERCASE_END 122

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

int main_str_manipulation() {
    char source[] = "Hello World";
    char destination[20];

    mystrcopy(destination,source);
    printf("%s\n", destination);

    leftstr(destination,source, 3);
    printf("%s\n", destination);

    reverstr(destination,source);
    printf("%s\n", destination);

    upstr(destination,source);
    printf("%s\n", destination);

    return 0;
}
