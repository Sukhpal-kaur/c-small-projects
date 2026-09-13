#include <stdio.h>

struct Account
{
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account *account)
{
    printf("\nEnter account number: ");
    scanf("%d", &account->accountNumber);

    printf("Enter account holder name: ");
    scanf(" %[^\n]", account->name);

    printf("Enter initial balance: ");
    scanf("%f", &account->balance);

    printf("\nAccount created successfully!\n");
}

void deposit(struct Account *account)
{
    float amount;

    printf("\nEnter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0)
    {
        account->balance = account->balance + amount;
        printf("Amount deposited successfully!\n");
    }
    else
    {
        printf("Invalid amount!\n");
    }
}

void withdraw(struct Account *account)
{
    float amount;

    printf("\nEnter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0)
    {
        printf("Invalid amount!\n");
    }
    else if (amount > account->balance)
    {
        printf("Insufficient balance!\n");
    }
    else
    {
        account->balance = account->balance - amount;
        printf("Amount withdrawn successfully!\n");
    }
}

void displayAccount(struct Account *account)
{
    printf("\n===== ACCOUNT DETAILS =====\n");
    printf("Account Number : %d\n", account->accountNumber);
    printf("Account Holder : %s\n", account->name);
    printf("Balance       : %.2f\n", account->balance);
}

int main()
{
    struct Account account;
    int choice;

    printf("===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");

    do
    {
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Display Account");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createAccount(&account);
                break;

            case 2:
                deposit(&account);
                break;

            case 3:
                withdraw(&account);
                break;

            case 4:
                displayAccount(&account);
                break;

            case 5:
                printf("\nBank system closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 5);

    return 0;
}