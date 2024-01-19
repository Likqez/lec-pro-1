#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 5
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

CARD cards[MAX_SIZE];

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

void print_cards(CARD cards[], int size) {
    for(int i = 0; i < size; i++) {
        print_card_struc(cards[i]);
    }
}

CARD input_card() {
    CARD card;
    printf("Enter ID: ");
    scanf("%d", &card.id);

    printf("Enter Name: ");
    scanf("%20s", card.name);

    printf("Enter Surname: ");
    scanf("%20s", card.surname);

    printf("Enter Age: ");
    scanf("%d", &card.age);

    printf("Enter Height: ");
    scanf("%d", &card.height);

    printf("Enter Weight: ");
    scanf("%d", &card.weight);

    printf("Enter Eye color: ");
    scanf("%10s", card.eye_color);

    printf("Enter Date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &card.date_of_birth.tm_mday, &card.date_of_birth.tm_mon, &card.date_of_birth.tm_year);
    card.date_of_birth.tm_mon -= 1; // tm_mon is in the range [0, 11]
    card.date_of_birth.tm_year -= 1900; // tm_year is the number of years since 1900

    return card;
}


int main() {
    char continue_input = 'y';
    for(int i = 0; i < MAX_SIZE; i++) {
        cards[i] = input_card();
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &continue_input);
        if(continue_input == 'n') {
            break;
        }
    }
    return 0;
}
