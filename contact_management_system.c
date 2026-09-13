#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 50

struct Contact
{
    char name[50];
    char phone[20];
    char email[100];
};

void addContact(struct Contact contacts[], int *count)
{
    if (*count >= MAX_CONTACTS)
    {
        printf("\nContact limit reached!\n");
        return;
    }

    printf("\nEnter name: ");
    scanf(" %[^\n]", contacts[*count].name);

    printf("Enter phone number: ");
    scanf(" %[^\n]", contacts[*count].phone);

    printf("Enter email: ");
    scanf(" %[^\n]", contacts[*count].email);

    (*count)++;

    printf("\nContact added successfully!\n");
}

void displayContacts(struct Contact contacts[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo contacts found.\n");
        return;
    }

    printf("\n===== CONTACT LIST =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nContact %d\n", i + 1);
        printf("Name  : %s\n", contacts[i].name);
        printf("Phone : %s\n", contacts[i].phone);
        printf("Email : %s\n", contacts[i].email);
    }
}

void searchContact(struct Contact contacts[], int count)
{
    char searchName[50];
    int i;
    int found = 0;

    printf("\nEnter name to search: ");
    scanf(" %[^\n]", searchName);

    for (i = 0; i < count; i++)
    {
        if (strcmp(contacts[i].name, searchName) == 0)
        {
            printf("\n===== CONTACT FOUND =====\n");
            printf("Name  : %s\n", contacts[i].name);
            printf("Phone : %s\n", contacts[i].phone);
            printf("Email : %s\n", contacts[i].email);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nContact not found.\n");
    }
}

int main()
{
    struct Contact contacts[MAX_CONTACTS];

    int count = 0;
    int choice;

    printf("===== CONTACT MANAGEMENT SYSTEM =====\n");

    do
    {
        printf("\n1. Add Contact");
        printf("\n2. Display Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addContact(contacts, &count);
                break;

            case 2:
                displayContacts(contacts, count);
                break;

            case 3:
                searchContact(contacts, count);
                break;

            case 4:
                printf("\nContact Management System closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 4);

    return 0;
}