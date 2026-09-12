#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int die1, die2, total;
    char choice = 'y';

    srand((unsigned int)time(NULL));

    printf("===== DICE ROLLING GAME =====\n");

    while (choice == 'y' || choice == 'Y')
    {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;

        total = die1 + die2;

        printf("\nDie 1 = %d\n", die1);
        printf("Die 2 = %d\n", die2);
        printf("Total = %d\n", total);

        printf("\nRoll again? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("\nGame ended. Thanks for playing!");

    return 0;
}