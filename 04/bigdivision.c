#include <stdio.h>
#include <ctype.h>

// Example by Prof!

void division(long int dividend, long int divisor, long int length) {
    int i, digits;
    int quotient;
    int comma = 0;

    //   In case of a negative value, we have to add a minus symbol

    if ((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) {
        printf("-");
    }

    //   Now we make them positive to simplifiy the calculation

    if (dividend < 0) {
        dividend *= -1;
    }

    if (divisor < 0) {
        divisor *= -1;
    }

    //  This is the main loop, which works just as if you would do it by hand.
    //  Try it out yourself

    for (i = 1; i <= length; ++i) {
        quotient = dividend / divisor;
        printf("%d", quotient);
        dividend = 10 * (dividend - (quotient * divisor));

        if (!comma && i < length) {
            printf(".");
            comma = 1;
        }
    }
}

int main_division() {
    char what;
    long int dividend, divisor, length;

    do {
        printf("(E)nglish or (D)eutsch? ");
        scanf(" %c", &what);

        if (toupper(what) == 'E') {
            printf("Welcome to BigDivision!\n");
            printf("Dividend: ");
            scanf("%ld", &dividend);
            while (dividend == 0) {
                printf("Dividend cannot be zero. Enter a valid value: ");
                scanf("%ld", &dividend);
            }

            printf("Divisor: ");
            scanf("%ld", &divisor);
            while (divisor == 0) {
                printf("Divisor cannot be zero. Enter a valid value: ");
                scanf("%ld", &divisor);
            }

            printf("Length: ");
            scanf("%ld", &length);
            while (length <= 0 || length >= 32000) {
                printf("Length must be between 1 and 32000. Enter a valid value: ");
                scanf("%ld", &length);
            }

            printf("Are you sure (y/n)? ");
        } else {
            printf("Willkommen zu BigDivision!\n");
            printf("Dividend: ");
            scanf("%ld", &dividend);
            while (dividend == 0) {
                printf("Dividend darf nicht null sein. Geben Sie einen gültigen Wert ein: ");
                scanf("%ld", &dividend);
            }

            printf("Divisor: ");
            scanf("%ld", &divisor);
            while (divisor == 0) {
                printf("Divisor darf nicht null sein. Geben Sie einen gültigen Wert ein: ");
                scanf("%ld", &divisor);
            }

            printf("Länge: ");
            scanf("%ld", &length);
            while (length <= 0 || length >= 32000) {
                printf("Länge muss zwischen 1 und 32000 liegen. Geben Sie einen gültigen Wert ein: ");
                scanf("%ld", &length);
            }

            printf("Sind Sie sicher (j/n)? ");
        }

        scanf(" %c", &what);

        printf("\n");
        if (toupper(what) == 'Y') {
            printf("%ld : %ld = ", dividend, divisor);
            division(dividend, divisor, length);
            printf("\n\n");
        }

        printf("Nochmal? (y/n) ");
        scanf(" %c", &what);
        printf("\n");

    } while (toupper(what) == 'Y');

    return 0;
}
