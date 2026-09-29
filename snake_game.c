#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10
#define MAX_SNAKE 100

void drawBoard(int snakeX[], int snakeY[], int length,
               int foodX, int foodY)
{
    int x, y, i;
    int printed;

    printf("\n");

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            if (x == foodX && y == foodY)
            {
                printf("*");
                continue;
            }

            printed = 0;

            for (i = 0; i < length; i++)
            {
                if (snakeX[i] == x && snakeY[i] == y)
                {
                    if (i == 0)
                        printf("O");
                    else
                        printf("o");

                    printed = 1;
                    break;
                }
            }

            if (!printed)
            {
                printf(".");
            }
        }

        printf("\n");
    }
}

int isCollision(int headX, int headY,
                int snakeX[], int snakeY[], int length)
{
    int i;

    /* Wall collision */
    if (headX < 0 || headX >= WIDTH ||
        headY < 0 || headY >= HEIGHT)
    {
        return 1;
    }

    /* Body collision */
    for (i = 0; i < length; i++)
    {
        if (snakeX[i] == headX &&
            snakeY[i] == headY)
        {
            return 1;
        }
    }

    return 0;
}

void placeFood(int snakeX[], int snakeY[], int length,
               int *foodX, int *foodY)
{
    int occupied;
    int i;

    do
    {
        *foodX = rand() % WIDTH;
        *foodY = rand() % HEIGHT;

        occupied = 0;

        for (i = 0; i < length; i++)
        {
            if (snakeX[i] == *foodX &&
                snakeY[i] == *foodY)
            {
                occupied = 1;
                break;
            }
        }

    } while (occupied);
}

int main()
{
    int snakeX[MAX_SNAKE];
    int snakeY[MAX_SNAKE];

    int length = 3;

    int foodX, foodY;
    int headX, headY;

    int dx = 1;
    int dy = 0;

    char move;
    int i;
    int gameOver = 0;

    srand((unsigned int)time(NULL));

    /* Initial snake position */
    snakeX[0] = 5;
    snakeY[0] = 5;

    snakeX[1] = 4;
    snakeY[1] = 5;

    snakeX[2] = 3;
    snakeY[2] = 5;

    placeFood(snakeX, snakeY, length, &foodX, &foodY);

    printf("===== SNAKE GAME =====\n");
    printf("Controls: W = Up, S = Down, A = Left, D = Right\n");
    printf("Enter Q to quit.\n");

    while (!gameOver)
    {
        drawBoard(snakeX, snakeY, length, foodX, foodY);

        printf("\nScore = %d\n", length - 3);
        printf("Enter move: ");
        scanf(" %c", &move);

        if (move == 'q' || move == 'Q')
        {
            printf("\nGame ended by player.\n");
            break;
        }

        /* Change direction */
        if ((move == 'w' || move == 'W') && dy != 1)
        {
            dx = 0;
            dy = -1;
        }
        else if ((move == 's' || move == 'S') && dy != -1)
        {
            dx = 0;
            dy = 1;
        }
        else if ((move == 'a' || move == 'A') && dx != 1)
        {
            dx = -1;
            dy = 0;
        }
        else if ((move == 'd' || move == 'D') && dx != -1)
        {
            dx = 1;
            dy = 0;
        }

        /* Calculate new head position */
        headX = snakeX[0] + dx;
        headY = snakeY[0] + dy;

        /* Check collision */
        if (isCollision(headX, headY,
                        snakeX, snakeY, length))
        {
            printf("\nGAME OVER!\n");
            break;
        }

        /* Move the snake body */
        for (i = length; i > 0; i--)
        {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        snakeX[0] = headX;
        snakeY[0] = headY;

        /* Check if food is eaten */
        if (headX == foodX && headY == foodY)
        {
            length++;

            if (length >= MAX_SNAKE)
            {
                printf("\nCongratulations! You won!\n");
                gameOver = 1;
            }
            else
            {
                placeFood(snakeX, snakeY, length,
                          &foodX, &foodY);

                printf("\nFood eaten! Snake grew.\n");
            }
        }
    }

    printf("Final Score = %d\n", length - 3);

    return 0;
}