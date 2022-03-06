#include<stdio.h>

int getFirstDayofTheYear(int year)
{
    int day = (year * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) /  400)) % 7;
    return day;
}

int main()
{
    char *month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, j, totalDays, weekDay = 0, spaceCounter = 0, year;

    printf("Enter Your Favourite Year:\n");
    scanf("%d", &year);
    printf("\n\n                   Wlcome To %d                   \n\n", year);

    //check leap year:
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        daysInMonth[1] = 29;
    }
    
    //get the first day of year:
    weekDay = getFirstDayofTheYear(year);
    for(i = 0; i<12;  i++)
    {
        printf("\n\n                        %s                          \n", month[i]);
        printf("\n\n    Sun    Mon    Tue    Wed    Thu    Fri   Sat\n");
        
        for(spaceCounter = 1; spaceCounter<= weekDay; spaceCounter++)
        {
            printf("       "); //7 space;
        }

        totalDays = daysInMonth[i];
        for(j = 1; j <= totalDays; j++)
        {
            printf("%7d", j);
            weekDay++;
            if(weekDay > 6)
            {
                weekDay = 0;
                printf("\n");
            }
        }
    }
    return  0;
}
