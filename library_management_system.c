#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 50

struct Book
{
    int bookId;
    char title[100];
    char author[50];
    int available;
};

void addBook(struct Book books[], int *count)
{
    if (*count >= MAX_BOOKS)
    {
        printf("\nLibrary is full!\n");
        return;
    }

    printf("\nEnter book ID: ");
    scanf("%d", &books[*count].bookId);

    printf("Enter book title: ");
    scanf(" %[^\n]", books[*count].title);

    printf("Enter author name: ");
    scanf(" %[^\n]", books[*count].author);

    books[*count].available = 1;

    (*count)++;

    printf("\nBook added successfully!\n");
}

void displayBooks(struct Book books[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n===== LIBRARY BOOKS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nBook ID   : %d\n", books[i].bookId);
        printf("Title     : %s\n", books[i].title);
        printf("Author    : %s\n", books[i].author);

        if (books[i].available == 1)
        {
            printf("Status    : Available\n");
        }
        else
        {
            printf("Status    : Issued\n");
        }
    }
}

void searchBook(struct Book books[], int count)
{
    int id;
    int i;
    int found = 0;

    printf("\nEnter book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].bookId == id)
        {
            printf("\n===== BOOK FOUND =====\n");
            printf("Book ID : %d\n", books[i].bookId);
            printf("Title   : %s\n", books[i].title);
            printf("Author  : %s\n", books[i].author);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nBook not found.\n");
    }
}

void issueBook(struct Book books[], int count)
{
    int id;
    int i;

    printf("\nEnter book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].bookId == id)
        {
            if (books[i].available == 1)
            {
                books[i].available = 0;
                printf("\nBook issued successfully!\n");
            }
            else
            {
                printf("\nBook is already issued.\n");
            }

            return;
        }
    }

    printf("\nBook not found.\n");
}

void returnBook(struct Book books[], int count)
{
    int id;
    int i;

    printf("\nEnter book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (books[i].bookId == id)
        {
            if (books[i].available == 0)
            {
                books[i].available = 1;
                printf("\nBook returned successfully!\n");
            }
            else
            {
                printf("\nBook is already available.\n");
            }

            return;
        }
    }

    printf("\nBook not found.\n");
}

int main()
{
    struct Book books[MAX_BOOKS];

    int count = 0;
    int choice;

    printf("===== LIBRARY MANAGEMENT SYSTEM =====\n");

    do
    {
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBook(books, &count);
                break;

            case 2:
                displayBooks(books, count);
                break;

            case 3:
                searchBook(books, count);
                break;

            case 4:
                issueBook(books, count);
                break;

            case 5:
                returnBook(books, count);
                break;

            case 6:
                printf("\nLibrary system closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 6);

    return 0;
}