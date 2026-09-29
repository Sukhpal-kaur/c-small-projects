#include <stdio.h>

#define MAX_ITEMS 50

struct Item
{
    char name[50];
    float price;
    int quantity;
};

void addItem(struct Item items[], int *count)
{
    if (*count >= MAX_ITEMS)
    {
        printf("\nShopping cart is full!\n");
        return;
    }

    printf("\nEnter item name: ");
    scanf(" %[^\n]", items[*count].name);

    printf("Enter price: ");
    scanf("%f", &items[*count].price);

    printf("Enter quantity: ");
    scanf("%d", &items[*count].quantity);

    (*count)++;

    printf("\nItem added to cart successfully!\n");
}

void displayCart(struct Item items[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nShopping cart is empty.\n");
        return;
    }

    printf("\n===== SHOPPING CART =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nItem %d\n", i + 1);
        printf("Name     : %s\n", items[i].name);
        printf("Price    : %.2f\n", items[i].price);
        printf("Quantity : %d\n", items[i].quantity);
        printf("Subtotal : %.2f\n",
               items[i].price * items[i].quantity);
    }
}

void generateBill(struct Item items[], int count)
{
    int i;
    float total = 0;

    if (count == 0)
    {
        printf("\nShopping cart is empty.\n");
        return;
    }

    printf("\n===== FINAL BILL =====\n");

    for (i = 0; i < count; i++)
    {
        float subtotal;

        subtotal = items[i].price * items[i].quantity;

        printf("%s x %d = %.2f\n",
               items[i].name,
               items[i].quantity,
               subtotal);

        total = total + subtotal;
    }

    printf("-------------------------\n");
    printf("Total Amount = %.2f\n", total);
}

int main()
{
    struct Item items[MAX_ITEMS];

    int count = 0;
    int choice;

    printf("===== SHOPPING CART SYSTEM =====\n");

    do
    {
        printf("\n1. Add Item");
        printf("\n2. Display Cart");
        printf("\n3. Generate Bill");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addItem(items, &count);
                break;

            case 2:
                displayCart(items, count);
                break;

            case 3:
                generateBill(items, count);
                break;

            case 4:
                printf("\nShopping cart closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 4);

    return 0;
}