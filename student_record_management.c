#include <stdio.h>

#define MAX_STUDENTS 50

struct Student
{
    char name[50];
    int rollNumber;
    float marks;
};

void addStudent(struct Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter student name: ");
    scanf(" %[^\n]", students[*count].name);

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNumber);

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;

    printf("\nStudent record added successfully!\n");
}

void displayStudents(struct Student students[], int count)
{
    int i;

    if (count == 0)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== STUDENT RECORDS =====\n");

    for (i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Name       : %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks      : %.2f\n", students[i].marks);
    }
}

void searchStudent(struct Student students[], int count)
{
    int rollNumber;
    int i;
    int found = 0;

    printf("\nEnter roll number to search: ");
    scanf("%d", &rollNumber);

    for (i = 0; i < count; i++)
    {
        if (students[i].rollNumber == rollNumber)
        {
            printf("\n===== STUDENT FOUND =====\n");
            printf("Name       : %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Marks      : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStudent record not found.\n");
    }
}

int main()
{
    struct Student students[MAX_STUDENTS];

    int count = 0;
    int choice;

    printf("===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");

    do
    {
        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                printf("\nProgram closed.");
                break;

            default:
                printf("\nInvalid choice!");
        }

    } while (choice != 4);

    return 0;
}