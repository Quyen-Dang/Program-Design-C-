/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
/*  This program is how the slot machine works. There are 14 symbols, and randomly 3 symbols for each spin.                     */
/*  The user enter the balance they have, they would be asked if they want to play.                                             */
/*  There are three cases: case 0 to quit, case 1 to play, or neither.                                                          */
/*  It would be 5 cents for each spin. If 3 symbols of the spin are the same, player win 100 cents, else loose 5 cents.         */
/*  After each spin, the user would be asked if they want to play, or quit.                                                     */
/*  If balance lesser than 5 cents, it is insufficient fund.                                                                    */
/*  Quyen Dang                                                                                                                  */
/*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int balance, play;
    int spin1, spin2, spin3;
    char slot[14][40] = {"Pineapple", "Kiwi", "Apple", "Orange", "Lime", "Peach", "Lemon",
                "Pear", "Banana", "Cherry", "Grape", "Blueberry", "Blackberry", "Apricot"};
    printf("Enter initial balance (in cents): ");
    scanf("%d", &balance);

    printf("Would you like to play (press 1 to play or 0 to quit)? ");
    scanf("%d",&play);

    if (play == 0)
    {
        printf("Thank you for playing!\nRemaining balance: %d", balance);
        return 0;
    }

    else if (play ==1)
    {

        do
        {
            if (balance < 5)
            {
                printf("Insufficient fund");
                return 0;
            }

            srand(time(NULL)); //make the random spin different each run
            spin1 = rand()%14; //random spin the symbol 0 - 13
            spin2 = rand()%14;
            spin3 = rand()%14;

            printf("%s %s %s", slot[spin1], slot[spin2], slot[spin3]);

            if (slot[spin1] == slot[spin2] && slot[spin2] == slot[spin3]) balance +=100;
            else balance -=5;

            printf("\nRemaining balance: %d \n", balance);

            printf("Would you like to play (press 1 to play or 0 to quit)? ");
            scanf("%d",&play);

            if (play != 0 && play != 1)
            {
                do //the user would be asked until enter 0 or 1
                {
                    printf("Press 1 to play or 0 to quit: ");
                    scanf("%d", &play);
                } while (play != 0 && play != 1);}

            if (play == 0)
            {
                printf("Thank you for playing!\nRemaining balance: %d", balance);
                return 0;
            }
        } while (play == 1);
    }
    else //when the user enter number neither 0 or 1, the machine will ask until they enter 0 or 1
    {
        do
        {
            printf("Press 1 to play or 0 to quit: ");
            scanf("%d", &play);
        } while (play !=0 && play != 1);
        if (play == 0)
            {
                printf("Thank you for playing!\nRemaining balance: %d", balance);
                return 0;
            }

        do //repeat the step when the user enter 1
        {
            if (balance < 5)
            {
                printf("Insufficient fund");
                return 0;
            }

            srand(time(NULL));
            spin1 = rand()%14;
            spin2 = rand()%14;
            spin3 = rand()%14;

            printf("%s %s %s", slot[spin1], slot[spin2], slot[spin3]);

            if (slot[spin1] == slot[spin2] && slot[spin2] == slot[spin3]) balance +=100;
            else balance -=5;

            printf("\nRemaining balance: %d \n", balance);

            printf("Would you like to play (press 1 to play or 0 to quit)? ");
            scanf("%d",&play);

            do
            {
                printf("Press 1 to play or 0 to quit: ");
                scanf("%d", &play);
            } while (play !=0 && play != 1);

            if (play == 0)
            {
                printf("Thank you for playing!\nRemaining balance: %d", balance);
                return 0;
            }
        } while (play == 1);
    }
return 0;
}
