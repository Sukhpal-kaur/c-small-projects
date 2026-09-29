#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6

void displayWord(char word[], char guessed[])
{
    int i;

    for (i = 0; word[i] != '\0'; i++)
    {
        if (guessed[i] == 1)
        {
            printf("%c ", word[i]);
        }
        else
        {
            printf("_ ");
        }
    }

    printf("\n");
}

int isWordComplete(char word[], char guessed[])
{
    int i;

    for (i = 0; word[i] != '\0'; i++)
    {
        if (guessed[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char word[] = "computer";
    char guessed[50] = {0};

    char guess;
    int tries = 0;
    int i;
    int found;

    printf("===== HANGMAN GAME =====\n");
    printf("Guess the hidden word!\n");

    while (tries < MAX_TRIES)
    {
        printf("\nWord: ");
        displayWord(word, guessed);

        printf("Enter a letter: ");
        scanf(" %c", &guess);

        guess = tolower(guess);
        found = 0;

        for (i = 0; word[i] != '\0'; i++)
        {
            if (word[i] == guess)
            {
                guessed[i] = 1;
                found = 1;
            }
        }

        if (found)
        {
            printf("Correct guess!\n");
        }
        else
        {
            tries++;
            printf("Wrong guess! Tries remaining: %d\n",
                   MAX_TRIES - tries);
        }

        if (isWordComplete(word, guessed))
        {
            printf("\nCongratulations! You guessed the word: %s\n",
                   word);
            return 0;
        }
    }

    printf("\nGame Over!");
    printf("\nThe word was: %s\n", word);

    return 0;
}