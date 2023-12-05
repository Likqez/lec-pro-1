//
// Created by lanzn on 05.12.2023.
//

#include <stdio.h>

#define DAYS_IN_MARCH           31;
#define START_DATE              22;
#define DIFF_START_END_MARCH    10; // 9 + 1. Because we want to start at the 1st, not the 0th day
#define START_MONTH             3;

const char* MONTH_NAMES[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dez"};

void output_easter(const int year, const int month, const int date) {
    printf("\n%d is Easter Sunday on %s %d%s is", year, MONTH_NAMES[month - 1], date, "st");
}

void find_easter(const int year) {
    const int A = year % 19;
    const int B = year % 4;
    const int C = year % 7;
    const int D = (19 * A + 24) % 30;
    const int E = (2 * B + 4 * C + 6 * D + 5) % 7;

    int current_date = START_DATE;
    int current_month = START_MONTH;
    int days_to_easter = D + E;

    if (current_date + days_to_easter > 31) {
        days_to_easter -= DIFF_START_END_MARCH; // subtract the remaining days of march
        current_month++;
        current_date = 1 + days_to_easter;
        output_easter(year, current_month, current_date);
    } else {
        current_date += days_to_easter;
        output_easter(year, current_month, current_date);
    }
}

int input_year(char text[]) {
    int input;
    printf("%s", text);
    scanf("%d", &input);
    return input;
}

int main_easter() {
    int year = input_year("Enter the year you want to check");
    if (year == 1954 || year == 1981) {
        printf("Error! Cannot find easter for 1954 or 1981");
        return -1;
    }

    find_easter(year);
    return 0;
}
