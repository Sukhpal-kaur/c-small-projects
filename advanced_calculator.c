#include <stdio.h>

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

int main()
{
    int choice;
    double num1, num2;

    printf("===== ADVANCED CALCULATOR =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4)
    {
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);
    }

    switch (choice)
    {
        case 1:
            printf("Result = %.2lf", add(num1, num2));
            break;

        case 2:
            printf("Result = %.2lf", subtract(num1, num2));
            break;

        case 3:
            printf("Result = %.2lf", multiply(num1, num2));
            break;

        case 4:
            if (num2 == 0)
            {
                printf("Error: Cannot divide by zero.");
            }
            else
            {
                printf("Result = %.2lf", divide(num1, num2));
            }
            break;

        case 5:
            printf("Calculator closed.");
            break;

        default:
            printf("Invalid choice.");
    }

    return 0;
}
