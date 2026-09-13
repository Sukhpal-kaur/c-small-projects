#include <stdio.h>

#define MAX_EXPENSES 50

void addExpense(float expenses[], int *count)
{
    if (*count >= MAX_EXPENSES)
    {
        printf("\nExpense limit reached!\n");
        return;
    }

    printf("\nEnter expense amount: ");
    scanf("%f", &expenses[*count]);

    (*count)++;

    printf("Expense added successfully!\n");
}

void showExpenses(float expenses[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo expenses recorded.\n");
        return;
    }

    printf("\n===== EXPENSES =====\n");

    for (i = 0; i < count; i++)
    {
        printf("Expense %d = %.2f\n", i + 1, expenses[i]);
    }
}

void showTotal(float expenses[], int count)
{
    int i;
    float total = 0;

    for (i = 0; i < count; i++)
    {
        total = total + expenses[i];
    }

    printf("\nTotal Expenses = %.2f\n", total);
}

int main()
{
    float expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    printf("===== EXPENSE TRACKER =====\n");

    do
    {
        printf("\n1. Add Expense");
        printf("\n2. Show Expenses");
        printf("\n3. Show Total");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addExpense(expenses, &count);
                break;

            case 2:
                showExpenses(expenses, count);
                break;

            case 3:
                showTotal(expenses, count);
                break;

            case 4:
                printf("\nExpense Tracker closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 4);

    return 0;
}