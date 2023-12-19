#include <stdio.h>
#include <string.h>
#include <time.h>
//
// Created by lanzn on 19.12.2023.
//
typedef struct card {
    int id;
    char name[21];
    char surname[21];
    int age, height, weight;
    char eye_color[11];
    struct tm date_of_birth;
} CARD;

void print_card_struc(CARD card) {
    printf("ID: %d\n", card.id);
    printf("Name: %s\n", card.name);
    printf("Surname: %s\n", card.surname);
    printf("Age: %d\n", card.age);
    printf("Height: %d\n", card.height);
    printf("Weight: %d\n", card.weight);
    printf("Eye color: %s\n", card.eye_color);
    printf("Date of birth: %d.%d.%d\n", card.date_of_birth.tm_mday, card.date_of_birth.tm_mon + 1,
           card.date_of_birth.tm_year + 1900);
}
CARD card;

int main_file_card_struct() {
    card.id = 1;
    strcpy(card.name, "Lukas");
    strcpy(card.surname, "Lanzner");
    card.age = 19;
    card.height = 192;
    card.weight = 80;
    strcpy(card.eye_color, "brown");
    card.date_of_birth = (struct tm) {0, 0, 0, 24, 8, 2004-1900};
    print_card_struc(card);
    return 0;
}
