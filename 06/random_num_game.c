#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
// Created by lanzn on 19.12.2023.
//

int get_random_number_for_game(int min, int max) {
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}

int min, max;
int mode, turn; // store if playing single or multiplayer and who's turn it is
int p1_guess, p2_guess;
int p1_count, p2_count;

void read_min_max() {
    printf("Enter min:");
    scanf("%i", &min);

    printf("\nEnter max:");
    scanf("%i", &max);

    printf("Range of numbers is %i to %i\n", min, max);
}

void ask_multi_or_single() {
    printf("Enter 1 for singleplayer or 2 for multiplayer:");
    scanf("%i", &mode);
    if (mode == 2) {
        printf("Mode: Multiplayer\n");
        turn ^= get_random_number_for_game(0, 1);
    } else printf("Mode: Singleplayer\n");
}

void play_multi(const int random_number) {
    while (p1_guess != random_number || p2_guess != random_number) {
        if (turn == 0) {
            printf("\nPlayer 1's guess:");
            scanf("%i", &p1_guess);
            p1_count++;
        } else {
            printf("\nPlayer 2's guess:");
            scanf("%i", &p2_guess);
            p2_count++;
        }
        if (p1_guess == random_number) {
            printf("Player 1 wins with %i guesses\n", p1_count);
            exit(0);
        } else if (p2_count == random_number) {
            printf("Player 2 wins with %i guesses\n", p2_count);
            exit(0);
        }
        if (!turn) {
            printf("%s", p1_guess > random_number ? "Too high" : "Too low");
        } else printf("%s", p2_guess > random_number ? "Too high" : "Too low");
        turn ^= 1;
    }
}

void play_single(const int random_number) {
    while (p1_guess != random_number) {
        printf("Enter your guess:");
        scanf("%i", &p1_guess);
        p1_count++;
        if (p1_guess == random_number) {
            printf("You win with %i guesses\n", p1_count);
        }
    }
}

int main_rand_game() {
    ask_multi_or_single();
    if (mode == 2) {
        min = 1;
        max = 100;
    } else read_min_max();
    const int random_number = get_random_number_for_game(min, max);
    if (mode == 2) {
        printf("Player %i starts\n", turn + 1);
        play_multi(random_number);
    } else if (mode == 1) {
        play_single(random_number);
    }
}
