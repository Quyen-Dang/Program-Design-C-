/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is written by Quyen Dang in order to calculate the parking cost at Tampa International Airport.                */
/*  The user enter the number of hours and minutes that the vehicle has parked.                                                 */
/*  The rate is free for first 60 minutes, $4 for next 20 minutes, an addition $2 for each next 20 minute, and $18 for 24 hour. */
/*  If the vehicle parked exceed the day (each 24 hour), the addition $2 for each 20 minute will be add to the cost.            */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
int main(void)
{
    int hour, minute, total_minute, cost;

    printf("Please enter the hour parked: ");
    scanf("%d", &hour);

    printf("\nPlease enter the minute parked: ");
    scanf("%d", &minute);

    if (hour < 0 || minute < 0 || minute > 61)
    {
        printf("\nInvalid input. Hour should be positive and minute should be in range 0 - 60.");//verify the input.
        return 0;
    }

    total_minute = hour * 60 + minute;

    if (hour < 24)
    {
        if (total_minute < 61)
            cost = 0;
        else if (total_minute < 81)
            cost = 4;
        else
        {
            cost = 4;
            while (total_minute > 81)
            {
                cost +=2;
                total_minute -=20;
                if (cost > 18)
                    cost = 18;
            }
         }
    }
    else
    {
        int day, min;
        day = hour/24;//calculate the number of days parked
        min = (hour - day*24)*60 + minute; //total minute for the new day parked.
        cost = 18*day; //cost for the whole days parked.
        if (hour%24 > 3) //each 20 minute is $2, so 3 hour is $18 - the maximum charge for a 24-hour parking.
            cost +=18;
        else
        {
            while (min > 0)
            {
            cost += 2;
            min -= 20;
            }
        }//counter back each 20 minute for $2 until the minute <= 0.
    }

        printf("\nTotal amount due ($): %d", cost);

    return (0);
}
