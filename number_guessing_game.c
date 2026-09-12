#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int secretNumber, guess;
    int attempts = 0;

    srand(time(NULL));

    secretNumber = rand() % 100 + 1;

    printf("===== NUMBER GUESSING GAME =====\n");
    printf("I have selected a number between 1 and 100.\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        attempts++;

        if (guess > secretNumber)
        {
            printf("Too high! Try again.\n");
        }
        else if (guess < secretNumber)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed it.\n");
            printf("Number of attempts = %d", attempts);
        }

    } while (guess != secretNumber);

    return 0;
}