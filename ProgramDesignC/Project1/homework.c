/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written by Quyen Dang in order to calculate how many days left for the homework.                            */
/*  The user enter the date of today and number of the days for doing the work.                                                 */
/*  The work would be collected only from Monday to Thursday.                                                                   */
/*  Therefore,the collect day would be added 1, 2, or 3 days if the due day falls in Sunday, Saturday, or Friday.               */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
int main(void)
{
    int i; //the position of the date in week: 0-Sunday, 1-Monday,...and so on.
    int days; //the number of days for doing the work.
    int day_of_week, day_collect, days_left;
    char*today [] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    printf("Please enter today's day (0 - 6): \n");
    scanf("%d", &i);
    if (i < 0 || i > 6)
    {
        printf("Invalid input. Today's day in the range 0-6.");
        return 0;
    } // this step to make sure the user enter the day in the week.

    printf("Please enter the number of day for doing homework: \n");
    scanf("%d", &days);

    day_of_week = days % 7; //the date in the week when whole weeks passed.

    day_collect = i + day_of_week; // the date in the week with the date start doing work.

    if (day_collect > 6)
        day_collect = day_collect % 7;

    switch (day_collect)
    {
    case 0:
        {
            day_collect = 1; // the date to collect the work is Monday if the date is Sunday, Friday, or Saturday.
            days_left = days +1;//because the date falls in Sunday.
            break;
        }
    case 5:
        {
            day_collect = 1;
            days_left = days + 3;//because the date falls in Friday.
            break;
        }
    case 6:
        {
            day_collect = 1;
            days_left = days + 2;//because the date falls in Saturday.
            break;
        }
    default:
        days_left = days;
    break;
    }

    i = day_collect;

    printf("The due date is %s.\n", today[i]);
    printf("The number of days until due date is %d.\n", days_left);
    return 0;
}






