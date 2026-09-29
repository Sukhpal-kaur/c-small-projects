#include <stdio.h>

void displayBoard(char board[])
{
    printf("\n");
    printf(" %c | %c | %c\n", board[0], board[1], board[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[3], board[4], board[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[6], board[7], board[8]);
}

int checkWinner(char board[])
{
    int winningPositions[8][3] =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    int i;

    for (i = 0; i < 8; i++)
    {
        int a = winningPositions[i][0];
        int b = winningPositions[i][1];
        int c = winningPositions[i][2];

        if (board[a] == board[b] &&
            board[b] == board[c])
        {
            return 1;
        }
    }

    return 0;
}

int checkDraw(char board[])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (board[i] >= '1' && board[i] <= '9')
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    char board[9] =
    {
        '1', '2', '3',
        '4', '5', '6',
        '7', '8', '9'
    };

    int player = 1;
    int position;
    char mark;

    printf("===== TIC-TAC-TOE GAME =====\n");

    while (1)
    {
        displayBoard(board);

        mark = (player == 1) ? 'X' : 'O';

        printf("\nPlayer %d (%c), enter position: ",
               player, mark);

        scanf("%d", &position);

        if (position < 1 || position > 9)
        {
            printf("Invalid position! Try again.\n");
            continue;
        }

        if (board[position - 1] == 'X' ||
            board[position - 1] == 'O')
        {
            printf("Position already occupied! Try again.\n");
            continue;
        }

        board[position - 1] = mark;

        if (checkWinner(board))
        {
            displayBoard(board);
            printf("\nPlayer %d (%c) wins!\n", player, mark);
            break;
        }

        if (checkDraw(board))
        {
            displayBoard(board);
            printf("\nIt's a draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}