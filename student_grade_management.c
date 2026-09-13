#include <stdio.h>

struct Student
{
    char name[50];
    int rollNumber;
    float marks[5];
    float total;
    float percentage;
};

int main()
{
    struct Student student;
    int i;

    student.total = 0;

    printf("===== STUDENT GRADE MANAGEMENT SYSTEM =====\n");

    printf("\nEnter student name: ");
    scanf(" %[^\n]", student.name);

    printf("Enter roll number: ");
    scanf("%d", &student.rollNumber);

    printf("\nEnter marks for 5 subjects:\n");

    for (i = 0; i < 5; i++)
    {
        printf("Subject %d: ", i + 1);
        scanf("%f", &student.marks[i]);

        student.total = student.total + student.marks[i];
    }

    student.percentage = student.total / 5;

    printf("\n===== STUDENT RESULT =====\n");
    printf("Name       : %s\n", student.name);
    printf("Roll Number: %d\n", student.rollNumber);
    printf("Total Marks: %.2f/500\n", student.total);
    printf("Percentage : %.2f%%\n", student.percentage);

    if (student.percentage >= 90)
    {
        printf("Grade      : A+\n");
    }
    else if (student.percentage >= 80)
    {
        printf("Grade      : A\n");
    }
    else if (student.percentage >= 70)
    {
        printf("Grade      : B\n");
    }
    else if (student.percentage >= 60)
    {
        printf("Grade      : C\n");
    }
    else if (student.percentage >= 50)
    {
        printf("Grade      : D\n");
    }
    else
    {
        printf("Grade      : F\n");
    }

    return 0;
}