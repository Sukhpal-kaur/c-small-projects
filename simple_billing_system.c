#include <stdio.h>

int main()
{
    int quantity, choice;
    float price, total = 0;

    printf("===== SIMPLE BILLING SYSTEM =====\n");

    do
    {
        printf("\n1. Add Item");
        printf("\n2. Generate Bill");
        printf("\n3. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter item price: ");
            scanf("%f", &price);

            printf("Enter quantity: ");
            scanf("%d", &quantity);

            total = total + (price * quantity);

            printf("Item added successfully!");
        }
        else if (choice == 2)
        {
            printf("\n===== FINAL BILL =====\n");
            printf("Total Amount = %.2f\n", total);
        }
        else if (choice == 3)
        {
            printf("\nThank you for shopping!");
        }
        else
        {
            printf("\nInvalid choice!");
        }

    } while (choice != 3);

    return 0;
}