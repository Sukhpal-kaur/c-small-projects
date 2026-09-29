#include <stdio.h>

void lengthConverter()
{
    int choice;
    float value, result;

    printf("\n===== LENGTH CONVERTER =====\n");
    printf("1. Kilometers to Meters\n");
    printf("2. Meters to Kilometers\n");
    printf("3. Meters to Centimeters\n");
    printf("4. Centimeters to Meters\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice)
    {
        case 1:
            result = value * 1000;
            printf("Result = %.2f meters\n", result);
            break;

        case 2:
            result = value / 1000;
            printf("Result = %.2f kilometers\n", result);
            break;

        case 3:
            result = value * 100;
            printf("Result = %.2f centimeters\n", result);
            break;

        case 4:
            result = value / 100;
            printf("Result = %.2f meters\n", result);
            break;

        default:
            printf("Invalid choice!\n");
    }
}

void temperatureConverter()
{
    int choice;
    float value, result;

    printf("\n===== TEMPERATURE CONVERTER =====\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter temperature: ");
    scanf("%f", &value);

    switch (choice)
    {
        case 1:
            result = (value * 9 / 5) + 32;
            printf("Result = %.2f Fahrenheit\n", result);
            break;

        case 2:
            result = (value - 32) * 5 / 9;
            printf("Result = %.2f Celsius\n", result);
            break;

        default:
            printf("Invalid choice!\n");
    }
}

void weightConverter()
{
    int choice;
    float value, result;

    printf("\n===== WEIGHT CONVERTER =====\n");
    printf("1. Kilograms to Grams\n");
    printf("2. Grams to Kilograms\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter value: ");
    scanf("%f", &value);

    switch (choice)
    {
        case 1:
            result = value * 1000;
            printf("Result = %.2f grams\n", result);
            break;

        case 2:
            result = value / 1000;
            printf("Result = %.2f kilograms\n", result);
            break;

        default:
            printf("Invalid choice!\n");
    }
}

int main()
{
    int choice;

    printf("===== UNIT CONVERTER =====\n");

    do
    {
        printf("\n1. Length Converter");
        printf("\n2. Temperature Converter");
        printf("\n3. Weight Converter");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                lengthConverter();
                break;

            case 2:
                temperatureConverter();
                break;

            case 3:
                weightConverter();
                break;

            case 4:
                printf("\nUnit Converter closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 4);

    return 0;
}