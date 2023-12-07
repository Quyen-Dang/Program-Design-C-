/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *    *  *  *  *  *  *  *  *  *  */
/*  The program is written to get only integer from the string that the user enter.    */
/*  The user will be asked to enter sentence.                                          */
/*  The program will read and print out only integer in that sentence.                 */
/*  Quyen Dang                                                                         */
/*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *    *  *  *  *  *  *  *  *  *  */
#include <stdio.h>
int main (void)
{
    char input;

    printf("Input: ");

    do
    {
        input = getchar();
        if (input >= '0'&& input <= '9') //the condition to be integer
            putchar(input); //print out the string with only integer from the input

    }while (input != '\n'); //The getchar function will read the input until the user enter to a new line

return 0;
}
