#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0))
    {
        return 1;
    }

    return 0;
}

int getDaysInMonth(int month, int year)
{
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }

    return days[month - 1];
}

int getFirstDay(int month, int year)
{
    int day = 1;
    int m;

    if (month < 3)
    {
        month += 12;
        year--;
    }

    m = month;

    day = (1 + (13 * (m + 1)) / 5 +
           year % 100 +
           (year % 100) / 4 +
           (year / 100) / 4 +
           5 * (year / 100)) % 7;

    return (day + 6) % 7;
}

int main()
{
    int month, year;
    int days, firstDay;
    int day;

    printf("===== SIMPLE CALENDAR =====\n");

    printf("\nEnter year: ");
    scanf("%d", &year);

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12)
    {
        printf("\nInvalid month!");
        return 0;
    }

    days = getDaysInMonth(month, year);
    firstDay = getFirstDay(month, year);

    printf("\n     %d / %d\n\n", month, year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    for (day = 0; day < firstDay; day++)
    {
        printf("    ");
    }

    for (day = 1; day <= days; day++)
    {
        printf("%3d ", day);

        if ((day + firstDay) % 7 == 0)
        {
            printf("\n");
        }
    }

    return 0;
}