#include <stdio.h>

int main()
{
    int answer, score = 0;

    printf("===== C PROGRAMMING QUIZ =====\n\n");

    printf("1. Which symbol is used to end a C statement?\n");
    printf("1. :\n");
    printf("2. ;\n");
    printf("3. .\n");
    printf("4. ,\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong answer!\n\n");
    }

    printf("2. Which function is used to display output in C?\n");
    printf("1. scanf()\n");
    printf("2. input()\n");
    printf("3. printf()\n");
    printf("4. display()\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong answer!\n\n");
    }

    printf("3. Which data type is used to store an integer?\n");
    printf("1. float\n");
    printf("2. char\n");
    printf("3. int\n");
    printf("4. double\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong answer!\n\n");
    }

    printf("4. Which loop executes its body at least once?\n");
    printf("1. for\n");
    printf("2. while\n");
    printf("3. do-while\n");
    printf("4. switch\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 3)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong answer!\n\n");
    }

    printf("5. Which symbol is used to get the address of a variable?\n");
    printf("1. *\n");
    printf("2. &\n");
    printf("3. #\n");
    printf("4. @\n");
    printf("Enter your answer: ");
    scanf("%d", &answer);

    if (answer == 2)
    {
        printf("Correct!\n\n");
        score++;
    }
    else
    {
        printf("Wrong answer!\n\n");
    }

    printf("===== QUIZ RESULT =====\n");
    printf("Your score = %d/5\n", score);

    if (score == 5)
    {
        printf("Excellent!");
    }
    else if (score >= 3)
    {
        printf("Good job!");
    }
    else
    {
        printf("Keep practicing!");
    }

    return 0;
}