#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char characters[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*";

    int length;
    int i;
    int totalCharacters = sizeof(characters) - 1;

    srand((unsigned int)time(NULL));

    printf("===== PASSWORD GENERATOR =====\n");

    printf("\nEnter password length: ");
    scanf("%d", &length);

    if (length <= 0)
    {
        printf("\nInvalid password length!");
        return 0;
    }

    printf("\nGenerated Password: ");

    for (i = 0; i < length; i++)
    {
        int index = rand() % totalCharacters;
        printf("%c", characters[index]);
    }

    printf("\n");

    return 0;
}